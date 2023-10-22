/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on October 11, 2023, 9:27 AM
 * 
 *      Project Description: 
 * 
 *          Using Display 7-Segments to show a counter from 0 to 9 and using interruptions (button falling edge). 
 *          
 */


#include <xc.h> //Library to Microchip Microcontrollers. 
#include "Fuses.h"//Library to set fuses of PIC. 

//Prototype functions.
void Configuration(void);

//Main function. 

void main(void) {

    while (1) {

    }

}

void Configuration(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    TRISB = 0x03; //Set pin 0 and 1 as input. 
    TRISD = 0x00; //Set D port as output. 
    
    LATB = 0x00; //Clear the ports. 
    LATD = 0x00; //Clear ports. 

    //Interrupts settings. 
    RCONbits.IPEN = 0; //Interrupt priority disabled. 
    INTCONbits.GIE = 1; //Global interrupt enabled. 
    INTCONbits.INT0IE = 1; //Interrupt 0 enabled. 
    INTCONbits.INT0IF = 0; //Interrupt flag cleared. 
    INTCON2bits.INTEDG0 = 0; //Interrupt falling edge. 

}