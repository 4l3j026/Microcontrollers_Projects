/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 9, 2023, 3:40 PM
 * 
 *      Project Description: 
 *          Using one button, change the led state press one time. 
 */


#include <xc.h> //Library to microchip microcontrollers. 
#include "Fuses.h"  //Library created to set fuses. 
#include <pic18f4550.h> //Library to 

//Prototype Functions. 
void Set_Registers();

void main(void) { //Main function. 

    while (1) { //Infinite Cycle. 

    }

}

//Develop function of PÏC registers. 

void Set_Registers() {

    OSCCON = 0x72; //Internal Oscillator and frequency of 8MHz. 
    ADCON = 0x0F; //Set all pins as digital.
    
    TRISAbits.RA0 = 1; //Set pin RA0 as input. 
    TRISAbits.RA1 = 0; //Set pin RA1 as output. 
    
    LATAbits.LA1 = 0; //Assign low state on pin. 
    
}

