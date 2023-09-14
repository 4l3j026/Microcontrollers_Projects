/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 12, 2023, 6:40 PM
 */


#include <xc.h> //Library to Microchip microcontrollers. 
#include "Fuses.h" //Library to set fuses of PIC. 

//Prototype functions. 
void Conf_Reg(void);

//Main function

void main(void) {

    while (1) {

    }

}

//Developing function.

void Conf_Reg(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    //
//    TRISAbits.RA0 = 1;
//    TRISAbits.RA1 = 1;
    TRISA = 0x03; 
    
    

}



