/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on February 1, 2024, 3:32 PM
 */


#include <xc.h>
#include <string.h>
#include "Fuses_Configuration.h"

//Prototype functions. 
void Configuration(void); //Function to set registers of pins, Interrupts and EUSART. 
void TX_Numbers(unsigned char Units, unsigned Tens); //Functions to send numbers. 
void Counter_Message(void); //Send data info. 

//Global variables. 
unsigned char Count0_Units = 0x30;
unsigned char Count0_Tens = 0x30;
unsigned char TX_Text_1 [] = {"0 Interrupt Counter : "};

//Main functions. 

void main(void) {

    //Call functions. 
    Configuration();

    while (1) {

    }

}

//Develop function of the registers. 

void Configuration(void) {

    OSCCON = 0x72; //Internal oscillator .
    //Set pins as digital. 
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;
    ANSELBbits.ANSB0 = 0;

    TRISBbits.RB0 = 1; //Set RB0 as input. 

    //Interrupt configuration. 
    INTCONbits.GIE = 1; //Global Interrupt Enabled. 
    RCONbits.IPEN = 0; //Interrupt Priority Disabled.
    INTCONbits.PEIE = 1; //Interrupt Peripheral Enabled. 
    PIE1bits.RC1IE = 1; //Reception enabled. 
    PIE1bits.TX1IE = 1; //Reception enabled. 
    PIR1bits.TX1IF = 0; //Clean flag transmitter.
    PIR1bits.RC1IF = 0; //Clean flag Receiver. 
    INTCONbits.INT0E = 1; //Interrupt 0 enabled. 
    INTCONbits.INT0F = 0; //Interrupt flag cleared. 
    INTCON2bits.INTEDG0 = 0; //Falling edge configuration. 

    //---- EUSART configuration. 
    SPBRG = 103; //Configuration 9600 bauds. 
    TRISCbits.RC6 = 1; //Enable pin RC6 (TX1).
    TRISCbits.RC7 = 1; //Enable pin RC7 (RX1).

    //---- Transmitter configuration TXSTA1 (TX). 
    TXSTA1bits.TX91 = 0; //9 bits transmitter disabled. 
    TXSTA1bits.TXEN1 = 1; //Transmit Enabled. 
    TXSTA1bits.SYNC1 = 0; //Asynchronous mode. 
    TXSTA1bits.BRGH1 = 1; //High baud rate. 

    //---- Receive configuration RCSTA1 register (RX).
    RCSTAbits.SPEN1 = 1; //Serial port enable bit. 
    RCSTAbits.RX91 = 0; //9 bits transmitter disabled. 
    RCSTAbits.CREN1 = 1; //Receive continuous enabled. 

    //---- Baud configuration BAUDCON1. 
    BAUDCON1bits.BRG16 = 0; //16 bits mode disabled. 

    /*
     
     Remember data buffers. 
     * 
        RCREG1; ----> Receive buffer.
        TXREG1; ----> Transmitter buffer.
      
     */

}

//Develop interrupt function. 

void __interrupt() TX_EUSART(void) {

    if (INTCONbits.INT0F) {

        INTCONbits.INT0IF = 0; //Clean the flag. 
        
        Counter_Message(); 

        Count0_Units++; //Counter of interrupt 0.

        if (Count0_Units == ':') { //Condition to reset counter of units and increment tens counter. 

            Count0_Units = 0x30; //Reset value to 0 in character ASCII ('0')
            Count0_Tens++; //Increment tens value. 

        }

        TX_Numbers(Count0_Tens, Count0_Units); //Call function to send data numbers. 

    }

}

void TX_Numbers(unsigned char Units, unsigned Tens) {

    while (!PIR1bits.TX1IF); //Wait for empty buffer. 
    TXREG1 = Units;

    while (!PIR1bits.TX1IF); //Wait for empty buffer. 
    TXREG1 = Tens;

    while (!PIR1bits.TX1IF); //Wait for empty buffer. 
    TXREG1 = 0x0D; //Send command to TXREG buffer the ASCII character \r (Return to Home).

}

void Counter_Message (void){
    
    for (int i = 0; i < strlen(TX_Text_1); i++){
        
       while (!PIR1bits.TX1IF); 
       TXREG1 = TX_Text_1[i];  
        
    }
    
}