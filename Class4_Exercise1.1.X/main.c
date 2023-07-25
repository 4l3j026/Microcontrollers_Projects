/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 22, 2023, 3:24 AM
 */
/*
 *   PROJECT DESCRIPTION : 
 * 
 * 
 *      This is a simple class exercise of microcontroller to use 
 *      all ports with specific sequence:
 
 *      1. Turn on all pins of port A
 *      2. 
 * 
 * 
 */

// Fuses 
// This two statements use to specific registers from PIC. 
#include <xc.h> // Compiler libraries. 
#include <pic18f4550.h> 
#include "Library.h"

//  Prototypes functions. 
void Settings(); // Set registers. 
void Exercise(); // Develop the exercise. 

//Global variables.
int Time = 500;

void main(void) {

    Settings(); //Calling the "Settings function". 

    while (1) { // Infinite loop. 
        Exercise();
    }
}

//  Developing function. 

void Settings(void) {

    //Oscillator control and digital pins. 
    OSCCON = 0x72;
    ADCON1 = 0x0F;

    // Ports TRIS configuration as outputs. 
    TRISA = 0;
    TRISB = 0;
    TRISC = 0;
    TRISD = 0;
    TRISE = 0;

    // Ports LAT configuration as low logic state. 
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;

}

//Developing led function. 

void Exercise(void) {

    LATA = 0xFF;
    __delay_ms(Time);
    LATA = 0x00;
    __delay_ms(Time);
    LATB = 0xFF;
    __delay_ms(Time);
    LATB = 0x00;
    __delay_ms(Time);
    LATC = 0xFF;
    __delay_ms(Time);
    LATC = 0x00;
    __delay_ms(Time);
    LATD = 0xFF;
    __delay_ms(Time);
    LATD = 0x00;
    __delay_ms(Time);
    LATE = 0xF;
    __delay_ms(Time);
    LATE = 0x0;
    __delay_ms(Time);    
    
}
