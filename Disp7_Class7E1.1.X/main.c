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
void Data_Display(void);
void Data_Display2(unsigned char i);
void __interrupt() INT(void);
//Variables and constants.
#define t 10

//Main function. 

void main(void) {

    //Calling functions. 
    Configuration();

    while (1) {

        Data_Display();
        Data_Display2(0);

    }

}

void Configuration(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    TRISA = 0x00; //Set A port as output. 
    TRISB = 0x03; //Set pin 0 and 1 as input. 
    TRISD = 0x00; //Set D port as output. 

    LATA = 0x00; //Clear port.
    LATB = 0x00; //Clear the ports. 
    LATD = 0x00; //Clear ports. 

    //Interrupts settings. 
    RCONbits.IPEN = 0; //Interrupt priority disabled. 
    INTCONbits.GIE = 1; //Global interrupt enabled. 
    INTCONbits.INT0IE = 1; //Interrupt 0 enabled. 
    INTCONbits.INT0IF = 0; //Interrupt flag cleared. 
    INTCON2bits.INTEDG0 = 0; //Interrupt falling edge. 

}

//Develop function display data. 

void Data_Display(void) {

    unsigned char Numbers [10] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xE7};

    
}

//Develop another function of display. 
void Data_Display2(unsigned char i){
    
    unsigned char Numbers_2 [10] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xE7};
    
    LATD = Numbers_2 [i];
    LATAbits.LA1 = 1; 
    
}


//Develop interrupt function. 

void __interrupt() INT() {



}
