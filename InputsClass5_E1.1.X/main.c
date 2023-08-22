/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on August 21, 2023, 5:50 PM
 */

//Adding Libraries 
#include <xc.h> //Library to microchip microcontrollers. 
#include "Fuses.h" //Personal Library to se fuses. 
#include <pic18f4550.h> //Library to PIC18F4550.

//Prototype functions.
void Configurations (void);




void main(void) {
    
    //Call functions.
    Configurations();
    
    
}

//Development function about configurations registers. 
void Configurations (){
    
    //Set pin RB0 & RB1 as input.
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1; 
    //Set pin RB2 & RB3 as output.
    TRISBbits.RB2 = 0; 
    TRISBbits.RB3 = 0; 
    
}