/* 
 * File:   dispense.h
 * Author: Dave Plater
 *
 * Created on 24 March 2018, 12:49 PM
 */

#include "dispense.h"

        struct
        {
            unsigned  orange : 1;
            unsigned  yellow : 1;
            unsigned  red    : 1;
            unsigned  green  : 1;
            unsigned  flash  : 1;
            unsigned  on     : 1;
            unsigned  redbias: 1;
            unsigned  grnbias: 1;
        } ledflag;
        
const uint8_t fgsmmsg[] = " Setup, 1=50,2=43,3=40,4=30,5=20,6=10,7=15,8=25..0";
/** Tasks:
 * SMS price settings: price_set
 * SMS Merchant URL in base64 */
/** gsmmsg contains:        
 * +CMGR: "REC UNREAD","+27766520007","Dave Plater","22/06/21,15:58:15+08"
 * Setup, 1=50,2=43,3=40,4=30,5=20,6=10,7=15,8=25..0
 *          32   2B   28   1E   14   0A   0F   19
 * pricestore = EEPROM address for 8 x uint8_t price store
 */

bool Read_Service(void)
{
    uint8_t x = 0;
    while(!SERVICE_PORT)
    {
        if(x)
        {
            led_switch(1);
            x = 0;
        }
        else
        {
            led_switch(0);
            x = 1;
        }
        delay_10mS(2);
    }
    return 1;
}

void price_set(void)
{
//   uint8_t smsmessage[] = " Setup, 1=0975,2=0975,3=1250,4=1190..";
    uint8_t *messagestore;
    uint16_t x;
    uint16_t y;
    uint16_t i;
    uint16_t vpchar;
//    strcpy(gsmmsg, smsmessage);
    messagestore = strstr(gsmmsg, "1=");
    
    if(!messagestore)
    {
        led_error(15);
        RESET();
    }
    srchbuf0 = strstr(gsmmsg, "..");
    if(!srchbuf0)
    {
        led_error(15);
        RESET();
    }
    vpchar = srchbuf0 - messagestore;//size of usable price data store
    i = 0;
    while(i < PRICES)
    {
        srchbuf0 = strchr(messagestore, '=');
        if(!srchbuf0)
        {
            led_error(15);
            RESET();
        }
        srchbuf0++;
        y = atoi(srchbuf0);
        messagestore = srchbuf0;
        vendprice = y;
        uint16_t z = i*2;
        DATAEE_WriteWord(pricestore + z, vendprice);
        vendprice = DATAEE_ReadWord(pricestore + z);
        prices[i] = vendprice;
        i++;
    }
    while(SERVICE_PORT)
    {
        ClrWdt();
    }
}

void price_init(void)
{
    uint8_t z;
    uint8_t x;
    x = 0;
    while(x < PRICES)
    {
        z = x*2;
        vendprice = DATAEE_ReadWord(pricestore + z);
        prices[x] = vendprice;
        x++;
    }
}
//TODO: extract channel number from price
void dispense(uint8_t chanel)
{
    uint8_t  x;
    uint16_t p;
    
   // chanel = extract_channel();
    x = 0;
    p = price;
    while(x < PRICES)
    {
        if(prices[x] == p) 
        {
            channum = x;//The channel number is determined by the matching price
            break;
        }
        x++;
    }
    if(x >= PRICES)// If x value matches or exceeds definition PRICES then wrong amount is entered
    {
        led_error(15);
        goto errexit;
    }
    else
    {
        led_switch(0); // Green = 0 started dispense
        vend_nosense(x);
        led_switch(1); // Red = 1 finished vend
    }
    errexit:
    ClrWdt();
}

uint16_t extract_channel(void)
{
    //Channel number is cents in price
    uint16_t pchan0;
    uint16_t pchan1;
    pchan0 = price / 100;
    pchan1 = pchan0 * 100;
    pchan0 = price - pchan1;
    return(pchan0);
}

void led_error(uint8_t nflashes)
{
    while(nflashes > 0)
    {
        led_switch(1);//Red
        delay_10mS(100);//1 second delay
        led_switch(2);//Off
        delay_10mS(50);//1/2 second delay
        nflashes--;
    }
    
}

void dispense_test(void)
{
    __delay_ms(900);
    uint8_t z = 0;
    while(z != 3)
    {
        z = Long_Press();
        switch(z)
        {
            case 1 : vend_nosense(channel); // Short press to vend
            led_switch(2);
            continue;
            case 2 : __delay_ms(50);
            channel = ++channel & 0x03; // Medium press to increment channel
            __delay_ms(50);
            led_switch(2);
            continue;
            case 3 : break; // Long press to exit
            default : continue;
        }
    }
}

uint8_t Long_Press(void)
{
    uint8_t x = 3, y = 0; //Return y, 1 = less than 2s, 2 = 2s to 3.9s and 3 = 4s or more
    TMR1_Initialize();
    PIR4bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;
    while(!SERVICE_PORT)
    {
        if(PIR4bits.TMR1IF)
        {
            led_switch(1); //Red = 2s to 6s
            y = 2;
            T1CONbits.TMR1ON = 0;
            if(x > 0)
            {
                --x;
            }
            else
            {
                y = 3;
                led_switch(0);//Green = 6s +
            }
            TMR1_Initialize();
            PIR4bits.TMR1IF = 0;
            T1CONbits.TMR1ON = 1;
        }
        else if(!y)
        {
            y = 1;
        }
    }
    switch(y)
    {
        case 2 : led_switch(1);
        break;
        case 1 : led_switch(0);
        break;
        default : led_switch(2);
    }
    return y;//Return y, 1 = less than 2s, 2 = 2s to 3.9s and 3 = 4s or more NULL = no press
}

void vend_nosense(uint8_t chanel)
{
    ClrWdt();
    switch(chanel)
    {
        case 0 :
            VEND1_SetHigh();
            break;
        case 1 :
            VEND2_SetHigh();
            break;
        case 2 :
            VEND3_SetHigh();
            break;
        case 3 :
            VEND4_SetHigh();
            break;
        case 4 :
            VEND5_SetHigh();
            break;
        case 5 :
            VEND6_SetHigh();
            break;
        case 6 :
            VEND7_SetHigh();
            break;
        case 7 :
            VEND8_SetHigh();
            break;
        default:
            slave_vend(chanel);
    }
    __delay_ms(1000);
    LATD = LATD & 0x0F;
    LATB = LATB & 0xF0;
    ClrWdt();
}

void slave_vend(uint8_t cnumber)
{
    if((cnumber >= PRICES) || (cnumber < 8))
    {
        COMRQ_SetLow();
        gsmbyte = EUSART2_Read();
        if(gsmbyte == 'S')
        {
            EUSART2_Write(cnumber);
        }
        COMRQ_SetHigh();
    }
}



uint8_t Check_Stock(void)
{
    uint8_t c;
    c = TRISA;
    LATA = LATA | 0x1E;
    Set_LED_in();
    TRISA  = 0xFF;//Bits 1 to 4 set to 1 read stock switch
    uint8_t x = 0;
    stock = PORTA & 0x1E;
    stock = PORTA & 0x1E;
    TRISA = c;
    LATA = LATA & 0xE1;
    LATA = stock | LATA; //Turn on stock leds if no stock
    return stock;
}

void Set_LED_out(void)
{
    TRISA  = TRISA  & 0xE1;
}

void Set_LED_in(void)
{
    TRISA  = TRISA  | 0x1E;//Bits 1 to 4 set to 1 read stock switch
}
/*
 * TRISAbits.TRISA1
 * LED1_SetAnalogMode() ANSELAbits.ANSELA1 = 1 - LED1_SetDigitalMode()
 * LED1_SetDigitalInput() - LED1_SetDigitalOutput()
 * LED1_GetValue()
*/
/*
 *  bool ledredflash; RLED_Toggle()
    bool ledgreenflash; GLED_Toggle()
    bool ledredon;RLED_SetHigh()
    bool ledgreenon;GLED_SetHigh()
    bool ledslow;
    bool ledfast;
    bool ledchange;
*/

void DATAEE_WriteWord(uint16_t bAdd, uint16_t bData)
{
    uint8_t x = (uint8_t)bData & 0x00FF;
    DATAEE_WriteByte(bAdd, x);
    x = (uint8_t)(bData >> 8);
    DATAEE_WriteByte(bAdd + 1, x);
}

uint16_t DATAEE_ReadWord(uint16_t bAdd)
{
    uint8_t x = DATAEE_ReadByte(bAdd);
    uint16_t y = (uint16_t) x;
    y = y & 0x00FF;
    x = DATAEE_ReadByte(bAdd + 1);//Read most significant byte
    uint16_t z = (uint16_t) x;
    z = z & 0x00FF;
    y = (y | (z << 8));
    return y;
}

void led_opperate(void)
{
    ledchange = 0;
    if(ledredon)
    {
        RDLED_SetHigh();
        GDLED_SetLow();
        RLED_SetHigh();
        GLED_SetLow();
    }
    if(ledgreenon)
    {
        GDLED_SetHigh();
        RDLED_SetLow();
        GLED_SetHigh();
        RLED_SetLow();
    }
}
void led_switch(uint8_t color)
{
    //color = 1 = red 0 = green 2 = off
    if(color == 1) //Red
    {
        RDLED_SetHigh();
        GDLED_SetLow();
        RLED_SetHigh();
        GLED_SetLow();
    }
    else if(color == 0) //Green
    {
        GDLED_SetHigh();
        RDLED_SetLow();
        GLED_SetHigh();
        RLED_SetLow();
    }
    else if(color == 2) //Off
    {
        RDLED_SetLow();
        GDLED_SetLow();
        RLED_SetLow();
        GLED_SetLow();
    }
    else
    {
        RLED_Toggle(); // 3 = toggle
        RDLED_Toggle();
        GDLED_Toggle();
        GLED_Toggle();
    }
}

void LED_colour(void)
{
    if(!ledflag.on)
    {
        TMR2_Stop();
        TMR2_Initialize();
        goto endled;
    }
    endled:
    NOP();
}


#if 0
void vend_dispense(uint8_t chanel)
{//Ensure all channels off
//    mdb_unlock();
    LATB = 0x00;
    LATD = 0x00;
    //Turn on motor common
    LATAbits.LA5 = 1;
    //Turn off button light common
    LATCbits.LC2 = 0;
    //Get channel bit
    chanmask = 0x01;
    chanmask = chanmask << chanel;
    set_motortime(chanel);
    while(!CMOUTbits.MC1OUT && !PIR0bits.TMR0IF)
    {
        LATB = chanmask & 0x0F;
        LATD = chanmask & 0xF0;
    }
    LATB = 0;
    LATD = 0;
    TMR0_StopTimer();
    if(PIR0bits.TMR0IF)
    {//Timeout no package has dropped
        set_motortime(chanel);
        //Wait for drop.
        while(!CMOUTbits.MC1OUT && !PIR0bits.TMR0IF){}
        if(PIR0bits.TMR0IF)
        {//Now we have a no stock situation
            venflags.error = 1;
            disable_channel(chanel);
            //No vend no pay
            vendprice = 0x00;
        }
    }
    
}

void set_motortime(uint8_t chanel)
{//void TMR0_Write16bitTimer(uint16_t timerVal)
    uint8_t i = DATAEE_ReadByte(chan1time + chanel);
    TMR0_StopTimer();
    PIR0bits.TMR0IF = 0;
    //Initialize timer at one second
    uint16_t time = second1;
    time = time - (second_5 * i);
    TMR0_WriteTimer(time);
    TMR0_StartTimer();
}

void find_highprice(void)
{
    char i = 0;
    highprice = pricevend[0];
    while(i < 8)
    {
        if(highprice < pricevend[i])
        {
            highprice = pricevend[i];
        }
        i++;
    }
}

void find_lowprice(void)
{
    char i = 0;
    lowprice = pricevend[0];
    while(i < 8)
    {
        if(lowprice > pricevend[i])
        {
            lowprice = pricevend[i];
        }
        i++;
    }

}

void create_chanmask(void)
{
    
}
void init_pricestore(void)
{
    //Transfer prices to pricevend[]
    char i = 0;
    while(i < 8)
    {
        pricevend[i] = DATAEE_ReadByte(pricestore + i);
        i++;
    }

}

//Read values stored in NVRam and initialize link and time flags.
void Init_vendmem(void)
{
    //Transfer prices to pricevend[]
    uint8_t i = 0;
    while(i < 8)
    {
        pricevend[i] = DATAEE_ReadByte(pricestore + i);
        i++;
    }
}


void disable_channel(uint8_t channel)
{
    uint8_t errormask = 0x01;
    errormask = errormask << channel;
    errormask = errormask | DATAEE_ReadByte(venderrors);
    DATAEE_WriteByte(venderrors, errormask);
}

void update_vends(uint8_t chanel)
{
    uint8_t x = DATAEE_ReadByte(vendstore + chanel);
    x++;
    DATAEE_WriteByte(vendstore + chanel, x);
}
#endif