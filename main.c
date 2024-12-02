/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K40
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "dispense.h"
/*
                         Main application
 */
void main(void)
{
    uint8_t channel;
    // Initialize the device
    SYSTEM_Initialize();
#ifndef __DEBUG
    WDTCON0bits.SEN = 1;
#endif
/* Wait for COMRQ low 
 * then wait for COMRQ to return high
 * then when COMRQ returns low again
 * transmit G for good and wait
 * for COMRQ high again
 */
/*Setup, 1=1001,2=2502,3=3203,4=8704
 * ,5=2805,6=3206,7=4207,8=12808
 * ,9=1009,10=1010,11=1111,12=1212
 * ,13=1313,14=1414,15=1515,16=1616..*/
    
    while (1)
    {
        if(!COMRQ_GetValue())
        {
            EUSART2_Write('R');
            while(!COMRQ_GetValue()){}
            channel = EUSART2_Read();
            if((channel < 16) & (channel > 7))
            {
                channel = channel - 8;
                dispense(channel);
            }
        }
        
        
        ClrWdt();
    }
}
/**
 End of File
*/