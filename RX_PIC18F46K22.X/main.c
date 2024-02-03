/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on February 2, 2024, 11:05 PM
 */


#include <xc.h>
#include <string.h>
#include "Fuses_Configuration.h"

//Prototype functions. 
void Configurations (void); 

//Variables. 

void main(void) {
    
    //Call functions. 
    Configurations(); 
    
    while (1){
        
        
        
    }

}

void Configurations (void){
    
    OSCCON = 0x72; //Set internal oscillator. 
    
    //Set pins as digital. 
    ANSELC = 0x00; 
    ANSELD = 0x00; 
    //Set pins as outputs. 
    TRISD = 0x00; 
    
    //---- Interrupts Configurations ----
    INTCONbits.GIE = 1; //Global Interrupt Enabled. 
    INTCONbits.PEIE = 1;  //Peripheral Interrupt Enabled. 
    RCONbits.IPEN = 0; //Interrupt Priority disabled. 
    
    PIE1bits.RC1IE = 1; //Receive Enabled. 
    PIR1bits.RC1IF = 0; //Receive Flag cleared. 
    
    //---- EUSART Configurations ----
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

void __interrupt () RX_EUSART (void){
    
    if (PIR1bits.RC1IF){
        
        
        
    }
    
}