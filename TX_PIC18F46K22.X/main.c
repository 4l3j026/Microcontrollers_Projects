/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on February 1, 2024, 3:32 PM
 */


#include <xc.h>
#include "Fuses_Configuration.h"

//Prototype functions. 
void Configuration (void); 

//Global variables. 


void main(void) {
    
    //Call functions. 
    Configuration(); 

    while (1) {

    }

}

//Develop function of the registers. 
void Configuration (void){
    
    OSCCON = 0x72; 
    
    //Interrupt configuration. 
    INTCONbits.GIE = 1; //Global Interrupt Enabled. 
    RCONbits.IPEN = 0; //Interrupt Priority Disabled.
    INTCONbits.PEIE = 1; //Interrupt Peripheral Enabled. 
    PIE1bits.RC1IE = 1; //Reception enabled. 
    PIE1bits.TX1IE = 1; //Reception enabled. 
    PIR1bits.TX1IF = 0; //Clean flag transmitter.
    PIR1bits.RC1IF = 0; //Clean flag Receiver. 
        
    //---- EUSART configuration. 
    SPBRG = 103; //Configuration 9600 bauds. 
    TRISCbits.RC6 = 1; //Enable pin RC6 (TX1).
    TRISCbits.RC7 = 1; //Enable pin RC7 (RX1).
    
    //---- Transmitter configuration TXSTA1 (TX). 
    TXSTA1bits.TX91 = 0; //9 bits transmitter disabled. 
    TXSTA1bits.TXEN1 = 1; //Transmit Enabled. 
    TXSTA1bits.SYNC1 = 0; //Asynchronous mode. 
    TXSTA1bits.BRGH = 1; //High baud rate. 
    
    //---- Receive configuration RCSTA1 register (RX).
    RCSTAbits.SPEN1 = 1; //Serial port enable bit. 
    RCSTAbits.RX91 = 0; //9 bits transmitter disabled. 
    RCSTAbits.CREN1 = 1; //Receive continuous enabled. 
    
    //---- Baud configuration BAUDCON1. 
    BAUDCON1bits.BRG16 = 0; //16 bits mode disabled. 
    
}