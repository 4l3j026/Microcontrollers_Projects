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
void Display_Function(unsigned char D1, unsigned char D2, unsigned char D3, unsigned char D4);
void __interrupt() INT(void);

//Variables and constants.
#define Time 100    
char Units = 0; //Create global variable for units counter. 
char Tens = 0; //Create global variable for tens counter.
char Hundreds = 0; //Create global variable for hundreds counter. 
//Save the numbers data inside a vector. 
unsigned char Numbers_2 [10] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xE7};

//Main function. 

void main(void) {

    //Calling settings registers function. 
    Configuration();

    //Infinite Loop. 
    while (1) {

        //Call function of display. 
        Display_Function(0, Hundreds, Tens, Units);

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

void Display_Function(unsigned char D1, unsigned char D2, unsigned char D3, unsigned char D4) {

    LATA = 0x01; //Select the display. 
    LATD = Numbers_2 [D1]; //Assign to port the number received from the parameter. 
    __delay_ms(Time); //Delay to change to another display. 

    LATA = 0x02; //Select the display. 
    LATD = Numbers_2 [D2]; //Assign to port the number received from the parameter. 
    __delay_ms(Time); //Delay to change to another display. 

    LATA = 0x04; //Select the display. 
    LATD = Numbers_2 [D3]; //Assign to port the number received from the parameter. 
    __delay_ms(Time); //Delay to change to another display.

    LATA = 0x08; //Select the display. 
    LATD = Numbers_2 [D4]; //Assign to port the number received from the parameter. 
    __delay_ms(Time); //Delay to change to another display. 

}

//Develop interrupt function. 

void __interrupt() INT() {

    if (INT0IF) { //Evaluate the flag interrupt. 

        INT0IF = 0; //Clean the flag. 
        Units++; //Increasing the counter of units. 

        if (Units == 10) { //Evaluate the limit of counter. 

            Units = 0; //Counter reset.
            Tens++; //Increasing the counter of tens. 

        } else if (Tens == 10) { //Evaluate the limit of counter. 

            Tens = 0; //Counter reset.
            Hundreds++; //Increasing the counter of hundreds. 

        } else if (Hundreds == 10) { //Evaluate the limit of counter. 

            Hundreds = 0; //Counter reset.

        }

    }

}
