/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SERVICE aliases
#define SERVICE_TRIS                 TRISAbits.TRISA0
#define SERVICE_LAT                  LATAbits.LATA0
#define SERVICE_PORT                 PORTAbits.RA0
#define SERVICE_WPU                  WPUAbits.WPUA0
#define SERVICE_OD                   ODCONAbits.ODCA0
#define SERVICE_ANS                  ANSELAbits.ANSELA0
#define SERVICE_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SERVICE_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SERVICE_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SERVICE_GetValue()           PORTAbits.RA0
#define SERVICE_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SERVICE_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SERVICE_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define SERVICE_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define SERVICE_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define SERVICE_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define SERVICE_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define SERVICE_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set VEND1 aliases
#define VEND1_TRIS                 TRISBbits.TRISB0
#define VEND1_LAT                  LATBbits.LATB0
#define VEND1_PORT                 PORTBbits.RB0
#define VEND1_WPU                  WPUBbits.WPUB0
#define VEND1_OD                   ODCONBbits.ODCB0
#define VEND1_ANS                  ANSELBbits.ANSELB0
#define VEND1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define VEND1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define VEND1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define VEND1_GetValue()           PORTBbits.RB0
#define VEND1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define VEND1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define VEND1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define VEND1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define VEND1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define VEND1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define VEND1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define VEND1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set VEND2 aliases
#define VEND2_TRIS                 TRISBbits.TRISB1
#define VEND2_LAT                  LATBbits.LATB1
#define VEND2_PORT                 PORTBbits.RB1
#define VEND2_WPU                  WPUBbits.WPUB1
#define VEND2_OD                   ODCONBbits.ODCB1
#define VEND2_ANS                  ANSELBbits.ANSELB1
#define VEND2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define VEND2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define VEND2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define VEND2_GetValue()           PORTBbits.RB1
#define VEND2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define VEND2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define VEND2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define VEND2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define VEND2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define VEND2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define VEND2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define VEND2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set VEND3 aliases
#define VEND3_TRIS                 TRISBbits.TRISB2
#define VEND3_LAT                  LATBbits.LATB2
#define VEND3_PORT                 PORTBbits.RB2
#define VEND3_WPU                  WPUBbits.WPUB2
#define VEND3_OD                   ODCONBbits.ODCB2
#define VEND3_ANS                  ANSELBbits.ANSELB2
#define VEND3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define VEND3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define VEND3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define VEND3_GetValue()           PORTBbits.RB2
#define VEND3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define VEND3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define VEND3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define VEND3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define VEND3_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define VEND3_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define VEND3_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define VEND3_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set VEND4 aliases
#define VEND4_TRIS                 TRISBbits.TRISB3
#define VEND4_LAT                  LATBbits.LATB3
#define VEND4_PORT                 PORTBbits.RB3
#define VEND4_WPU                  WPUBbits.WPUB3
#define VEND4_OD                   ODCONBbits.ODCB3
#define VEND4_ANS                  ANSELBbits.ANSELB3
#define VEND4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define VEND4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define VEND4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define VEND4_GetValue()           PORTBbits.RB3
#define VEND4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define VEND4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define VEND4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define VEND4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define VEND4_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define VEND4_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define VEND4_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define VEND4_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()              PORTDbits.RD0
#define RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetPullup()             do { WPUDbits.WPUD0 = 1; } while(0)
#define RD0_ResetPullup()           do { WPUDbits.WPUD0 = 0; } while(0)
#define RD0_SetAnalogMode()         do { ANSELDbits.ANSELD0 = 1; } while(0)
#define RD0_SetDigitalMode()        do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSELD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set COMRQ aliases
#define COMRQ_TRIS                 TRISDbits.TRISD2
#define COMRQ_LAT                  LATDbits.LATD2
#define COMRQ_PORT                 PORTDbits.RD2
#define COMRQ_WPU                  WPUDbits.WPUD2
#define COMRQ_OD                   ODCONDbits.ODCD2
#define COMRQ_ANS                  ANSELDbits.ANSELD2
#define COMRQ_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define COMRQ_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define COMRQ_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define COMRQ_GetValue()           PORTDbits.RD2
#define COMRQ_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define COMRQ_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define COMRQ_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define COMRQ_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define COMRQ_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define COMRQ_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define COMRQ_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define COMRQ_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set COMAK aliases
#define COMAK_TRIS                 TRISDbits.TRISD3
#define COMAK_LAT                  LATDbits.LATD3
#define COMAK_PORT                 PORTDbits.RD3
#define COMAK_WPU                  WPUDbits.WPUD3
#define COMAK_OD                   ODCONDbits.ODCD3
#define COMAK_ANS                  ANSELDbits.ANSELD3
#define COMAK_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define COMAK_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define COMAK_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define COMAK_GetValue()           PORTDbits.RD3
#define COMAK_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define COMAK_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define COMAK_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define COMAK_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define COMAK_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define COMAK_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define COMAK_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define COMAK_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set VEND5 aliases
#define VEND5_TRIS                 TRISDbits.TRISD4
#define VEND5_LAT                  LATDbits.LATD4
#define VEND5_PORT                 PORTDbits.RD4
#define VEND5_WPU                  WPUDbits.WPUD4
#define VEND5_OD                   ODCONDbits.ODCD4
#define VEND5_ANS                  ANSELDbits.ANSELD4
#define VEND5_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define VEND5_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define VEND5_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define VEND5_GetValue()           PORTDbits.RD4
#define VEND5_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define VEND5_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define VEND5_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define VEND5_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define VEND5_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define VEND5_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define VEND5_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define VEND5_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set VEND6 aliases
#define VEND6_TRIS                 TRISDbits.TRISD5
#define VEND6_LAT                  LATDbits.LATD5
#define VEND6_PORT                 PORTDbits.RD5
#define VEND6_WPU                  WPUDbits.WPUD5
#define VEND6_OD                   ODCONDbits.ODCD5
#define VEND6_ANS                  ANSELDbits.ANSELD5
#define VEND6_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define VEND6_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define VEND6_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define VEND6_GetValue()           PORTDbits.RD5
#define VEND6_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define VEND6_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define VEND6_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define VEND6_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define VEND6_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define VEND6_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define VEND6_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define VEND6_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set VEND7 aliases
#define VEND7_TRIS                 TRISDbits.TRISD6
#define VEND7_LAT                  LATDbits.LATD6
#define VEND7_PORT                 PORTDbits.RD6
#define VEND7_WPU                  WPUDbits.WPUD6
#define VEND7_OD                   ODCONDbits.ODCD6
#define VEND7_ANS                  ANSELDbits.ANSELD6
#define VEND7_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define VEND7_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define VEND7_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define VEND7_GetValue()           PORTDbits.RD6
#define VEND7_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define VEND7_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define VEND7_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define VEND7_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define VEND7_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define VEND7_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define VEND7_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define VEND7_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set VEND8 aliases
#define VEND8_TRIS                 TRISDbits.TRISD7
#define VEND8_LAT                  LATDbits.LATD7
#define VEND8_PORT                 PORTDbits.RD7
#define VEND8_WPU                  WPUDbits.WPUD7
#define VEND8_OD                   ODCONDbits.ODCD7
#define VEND8_ANS                  ANSELDbits.ANSELD7
#define VEND8_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define VEND8_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define VEND8_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define VEND8_GetValue()           PORTDbits.RD7
#define VEND8_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define VEND8_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define VEND8_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define VEND8_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define VEND8_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define VEND8_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define VEND8_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define VEND8_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/