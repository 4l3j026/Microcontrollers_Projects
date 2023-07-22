/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 22, 2023, 12:57 AM
 */

// Fuses 
// This two statements use to specific registers from PIC. 
#include <xc.h>
#include <pic18f4550.h>
#include "Configuration.h"  // Use of simple library of some registers/fuses. 

//Crystal frequency 
#define _XTAl_FREQ 8000000

//  Prototypes functions. 
void Settings();

void main(void) {

    Settings(); //Calling the "Settings function". 


    while (1) { // Infinite loop. 

    }
}

//  Developing function. 

void Settings() {

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