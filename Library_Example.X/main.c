/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 12, 2023, 2:08 PM
 */


#include <xc.h> //Library to all microchip uControllers. 
#include <pic18f4550.h> //Library to specific registers of PIC18F4550.
#include "Configuration_1.h" //Library example with some fuses. 


//Prototype functions.
void Settings();

//Main function. 

void main(void) {
    Settings(); //Call function "Settings."
    while (1) {

        RA0 ^= 1;
        __delay_ms(500);

    }
}

//Develop function with some PIC registers.

void Settings() {

    OSCCON = 0x72;
    ADCON1 = 0x0F;
    TRISAbits.RA0 = 0;
    LATAbits.LA0 = 0;

}