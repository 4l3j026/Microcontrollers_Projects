/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 2, 2023, 12:41 PM
 */


#include <xc.h> //  This statement is a library for any microcontroller of microchip. 

// Configuration of some important fuses. 
/*
 * This statement refer to set speed of internal oscillator
 * Frequency OSCillator (FOSC) = Use INTernal OSCillator in High Speed (INTOSC_HS) 
 * In this microcontroller High Speed is from > 4 Mhz 
 */
#pragma config FOSC = INTOSC_HS //  -------------?
/*
 * This pragma configuration use to power off the "Watch Dog Timer" 
 * Because we don't need restart the microcontroller after some time. 
 */
#pragma config WDT = OFF //  -------------?
/*
 * This pragma configuration use to power off the "Low Voltage Programming"
 * Because we don't need take the high state as 3.3V but as 5V. 
 */
#pragma config LVP = OFF //  -------------?

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
    OSCCON = 0x72; //  -------------?
    /*
     * (Analog/Digital CONtrol) ADCON 1
     * This register set ports as analog or digital I/O. 
     * Bit 7 - Bit 6: Unimplemented bits = 00.
     * Bit 5 - Bit 4: Set voltage reference +bit 5 and - bit 4 = 00.
     * Bit 3 - Bit 0: Port configuration bits analog or digital, in this case all pins are digital = 1111.  
     */
    ADCON1 = 0x0F; //  -------------?
    /*
     * With this register you can set specific pin from A port as output (0) or input (1). 
     */
    TRISAbits.RA0 = 0; //  -------------?

    /*
     * But you can set the register of this way: 
     * TRISA = 0b00000000; //Here I set all pins from A port as outputs. 
     * And it´s the same way to the LAT and POR registers. 
     */


    /*
     * With this register you can set specific pin from A port on low state (0 / 0v) or high state (1 / 5V). 
     * Important note: Due to security reasons we set the pin as low state.
     */
    LATAbits.LA0 = 0; //  -------------?

    //Pin 6 set

    TRISAbits.RA6 = 0;
    LATAbits.LA6 = 0;

    //Important resgiters 
    //CONFIG1L : 0b00000000; 
    //CONFIG1H : 0b00001000;
    TRISAbits.RA4 = 0; 
    LATAbits.LA4 = 0; 
    
    TRISAbits.RA1 = 0;
    LATAbits.LA1 = 0; 
    
    TRISAbits.RA2 = 0; 
    LATAbits.LA2 = 0; 
    
    
    //  Infinite loop to perform microcontroller process. 
    while (1) {
        /*
         Here, with two lines I program an led to turn on and off every 500 ms. 
         */
        LATAbits.LA0 ^= 1;
        LATAbits.LA4 ^= 1;
        LATAbits.LA1 ^= 1;
        LATAbits.LA2 ^= 1;
        //LATAbits.LA6 ^= 1;
        __delay_ms(500);

    }

}