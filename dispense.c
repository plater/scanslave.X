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

void dispense(uint8_t chanel)
{
    uint8_t  x;
    uint16_t p;
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
    }
    __delay_ms(1000);
    LATD = LATD & 0x8F;
    LATB = LATB & 0xF0;
    ClrWdt();
}
#if 0
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

#endif


