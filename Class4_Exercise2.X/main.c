/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 13, 2023, 11:05 PM
 */

/*
 *   PROJECT DESCRIPTION : 
 * 
 * 
 *      This is a simple exercise of microcontroller to use the all pins of 
 *      the all ports, set all the registers of each port of PIC18F4550. 
 * 
 * 
 */

#include <xc.h> //  This statement is a library for any microcontroller of microchip.
#include <pic18f4550.h> //This statement is a library specifically for PIC18F4550. 

// Configuration of some important fuses. 
/*
 * This statement refer to set speed of internal oscillator
 * Frequency OSCillator (FOSC) = Use INTernal OSCillator and enable the pin 6 of the Port A
 * (Wich by default is used to second oscillattor).
 */
#pragma config FOSC = INTOSCIO_EC //  -------------- Up description
/*
 * This pragma configuration use to power off the "Watch Dog Timer" 
 * Because we don't need restart the microcontroller after some time. 
 */
#pragma config WDT = OFF //  -------------^
/*
 * This pragma configuration use to power off the "Low Voltage Programming"
 * Because we don't need take the high state as 3.3V but as 5V. 
 */
#pragma config LVP = OFF //  -------------^

//Define time delays
/*
 * This is a function by library <xc.h> for calculate of delays. 
 * So we're programming the maximum speed of internal oscillator (Wich is 8Mhz).  
 */
#define _XTAL_FREQ 8000000  //  -------------?

void main(void) { //  This statement is the main and the most important function.


    //Configuration of other registers. 
    /*
     * (OSCillator CONtrol) OSCCON
     * Bit 7: IDLE Enable bit = 0.
     * Important note: IDLE means: Inactive, Dormant, Low-power, Energy-saving.     
     * Bit 6 - Bit 4: Set 8Mhz frequency of internal crystal = 111.
     * Bit 3 - Bit 2: Set state of oscillator (Stable or time running) as = 00.
     * Bit 1 - Bit 0: Set internal oscillator as = 10. 
     */
    OSCCON = 0x72; //  -------------^
    /*
     * (Analog/Digital CONtrol) ADCON 1
     * This register set ports as analog or digital I/O. 
     * Bit 7 - Bit 6: Unimplemented bits = 00.
     * Bit 5 - Bit 4: Set voltage reference +bit 5 and - bit 4 = 00.
     * Bit 3 - Bit 0: Port configuration bits analog or digital, in this case all pins are digital = 1111.  
     */
    ADCON1 = 0x0F; //  -------------^
    /*
     * With this register you can set specific pin from A port as output (0) or input (1). 
     */
        
    // Here, we�re set all ports as outputs. 
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;
    // Here we�re set all pins of each port as low logic state. 
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;
   

    //  Infinite loop to perform microcontroller process. 
    while (1) {
        /*
         Here, with two lines I program an led to turn on and off every 500 ms. 
         */
        LATA ^= 0xFF;
        LATB ^= 0xFF;
        LATC ^= 0xFF;
        LATD ^= 0xFF;
        LATE ^= 0xFF;
        __delay_ms(500);
        /*
         * This function use ms (__delay_ms(n value)) and use us (__delay_us(n value))
         */

    }

}