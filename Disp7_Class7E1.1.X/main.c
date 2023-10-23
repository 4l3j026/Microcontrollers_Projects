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
void Data_Display(unsigned char N, unsigned char D);
void __interrupt() INT(void);

//Variables and constants.
#define Time 10 //Create time constant 

//Main function. 

void main(void) {

    //Calling functions. 
    Configuration();

    while (1) {

        /*
         Here, we're calling the function, where first parameter is: 
                - One number from 0 to 9 due to display limit. 
         And the second parameter is: 
                - One number from 0 to 3 because of the number of displays. 
         */
        Data_Display(6, 1);
        __delay_ms(800);
        Data_Display(4, 0);
        __delay_ms(400);
        Data_Display(8, 2);
        __delay_ms(400);
        Data_Display(2,3);
        __delay_ms(400);

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

//Develop another function of display. 

void Data_Display(unsigned char N, unsigned char D) {

    //Save the numbers data inside a vector. 
    unsigned char Numbers_2 [10] = {0xBF, 0x86, 0xDB, 0xCF, 0xE6, 0xED, 0xFD, 0x87, 0xFF, 0xE7};
    //Save the display address inside a vector. 
    unsigned char Display [4] = {0x01, 0x02, 0x04, 0x08};

    //Assign to ports the parameters value to show on display. 
    LATD = Numbers_2 [N];
    LATA = Display [D];

}


//Develop interrupt function. 

void __interrupt() INT() {

}
