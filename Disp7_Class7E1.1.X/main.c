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
#define Time 1000 //Create time constant  
#define Time_2 500
char Units = 0; //Create global variable for units counter. 
char Tens = 0; //Create global variable for tens counter.
char Hundreds = 0; //Create global variable for hundreds counter. 
//Save the numbers data inside a vector. 
unsigned char Numbers_2 [10] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xE7};
//Save the display address inside a vector. 
unsigned char Display [5] = {0x00, 0x01, 0x02, 0x04, 0x08};


//Main function. 

void main(void) {

    //Calling settings registers function. 
    Configuration();

    //Infinite Loop. 
    while (1) {

        //Data_Show(); //Cal function to show '0' on display. 
        Display_Function(3, 7, 4, 1);

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

    LATA = 0x01; 
    LATD = Numbers_2 [D1];
    __delay_ms(Time_2);
    LATA = 0x02; 
    LATD = Numbers_2 [D2];
    __delay_ms(Time_2);
    LATA = 0x04; 
    LATD = Numbers_2 [D3];
    __delay_ms(Time_2);
    LATA = 0x08; 
    LATD = Numbers_2 [D4];
    __delay_ms(Time_2);

}

//Develop interrupt function. 

void __interrupt() INT() {

    if (INT0IF) {

        INT0IF = 0;
        Units++;

        if (Units == 10) {

            Units = 0;
            Tens++;

        } else if (Tens == 10) {

            Tens = 0;
            Hundreds++;

        } else if (Hundreds == 10) {

            Hundreds = 0;

        }

    }

}

