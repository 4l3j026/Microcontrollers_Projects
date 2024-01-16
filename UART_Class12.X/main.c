/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on January 10, 2024, 4:04 PM
 */


#include <xc.h> //Library to Microchip Microcontrollers. 
#include <stdint.h> //Library to use uint8_t (unsigned integer of 1 byte).
#include "Fuses.h" //Library where fuses are configurated. 


//Prototype functions. 
void Configurations(void);

//Global variables. 
uint8_t Counter_Button1 = 0; //Unsigned integer of 8 bits. 
//union Value Data; 

union Value {
    uint8_t Int_Value [1];
    unsigned char Char_Value [1];

} Data;

//Create unsigned integer of 4 bits. 

struct test {
    unsigned int Var : 4;

} value;

//Main function. 

void main(void) {

    //Call functions. 
    Configurations();

    //Infinity Loop.
    while (1) {

    }

}

//Develop Configuration function. 

void Configurations(void) {

    OSCCON = 0x72; //Oscillator Control register. 
    ADCON1 = 0x0F; //Analog & Digital Control register. 

    TRISCbits.RC6 = 0; //Set RX pin as output. 
    TRISCbits.RC7 = 1; //Set Tx pin as input. 

    //UART Registers. 
    SPBRG = 0X0C; //Baud rate generator
    RCSTA = 0x90; //Receive status and control register. 
    TXSTA = 0x20; //Transmit status and control register. 

    //Interrupt Registers. 
    INTCONbits.GIE = 1; //Global Interrupt enabled. 
    RCONbits.IPEN = 0; //Interrupt priority disabled.
    //INT0 configuration. 
    INTCONbits.INT0E = 1; //Interrupt on pin RB0 enabled. 
    INTCONbits.INT0F = 0; //Flag interrupt cleared.
    INTCON2bits.INTEDG0 = 0; //Interrupt set as falling edge. 
    //INT2 configuration. 
    INTCON3bits.INT2E = 1; //Interrupt on pin RB2 enabled. 
    INTCON3bits.INT2F = 0; //Flag interrupt cleared. 
    INTCON2bits.INTEDG2 = 1; //Interrupt set as rising edge. 

}

void __interrupt() INT_UART_TX(void) {

    if (INTCONbits.INT0IF) { //Test if there is a change in the port. 

        value.Var++; //Increment the counter every single state change. 
        INTCONbits.INT0IF = 0; //Clean the flag interrupt.




    }
    if (INTCON3bits.INT2F) { //Test if there is a change in the port. 

        Counter_Button1++; //Increment the counter every single state change.
        INTCON3bits.INT2F = 0; //Clean the flag interrupt. 

    }

}

