/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on January 21, 2024, 12:01 AM
 */


/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on January 10, 2024, 4:04 PM
 */

#include <pic18f4550.h>



#include <xc.h> //Library to Microchip Microcontrollers.
#include <stdio.h> //Library to use sprintf. 
#include <stdint.h> //Library to use uint8_t (unsigned integer of 1 byte).
#include <string.h> //Library to use strlen function. 
#include "Fuses_Set.h" //Library where fuses are configurated. 


//Prototype functions. 
void Configurations(void);

//Global variables. 
unsigned char Counter_Button1 = 0;
unsigned char Counter_Button2 = 0;
unsigned char Text_Int2 [28];
unsigned char Text_Int0[28] = {"INT0 Counter: "};
//union Value Data; 

union Value {
    uint8_t Int_Value [1];
    unsigned char Char_Value [1];

} Data;

union Send {
    int Int_Var[1];
    char Char_Var[2];

} Buffer;

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
    SPBRG = 0x0C; //Baud rate generator and starts on 9600 Bauds.
    RCSTA = 0x90; //Receive status and control register. 
    TXSTA = 0x20; //Transmit status and control register. 

    //Interrupt Registers. 
    INTCONbits.GIE = 1; //Global Interrupt enabled.     
    INTCONbits.PEIE = 1; //Peripheral Interrupt Enabled. 
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

        INTCONbits.INT0IF = 0; //Clean the flag interrupt. 
        Counter_Button1++; //Increment the counter every single state change.

        /* ---------- Another way to program counter without sprintf function. ----------*/
        //        Buffer.Char_Var[0] = 0x30 + Counter_Button1; //Send jASCII characters from 0 (0x30) and plus the counter. 
        //
        //        for (int j = 0; j < strlen(Text_Int0); j++) {
        //
        //            while (!PIR1bits.TX1IF); //Wait for empty buffer.
        //            TXREG = Text_Int0[j]; //Assign to the TX buffer each character of the array. 
        //
        //        }
        //
        //        while (!PIR1bits.TX1IF);
        //        TXREG = Buffer.Char_Var[0];
        //
        //        while (!PIR1bits.TX1IF); //Wait for empty buffer. 
        //        TXREG = 0x0D; //Send command to TXREG buffer the ASCII character \r (Return to Home).

        sprintf(Text_Int0, "INT0 Counter: %d", Counter_Button1);

        for (int i = 0; i < strlen(Text_Int0); i++) {

            while (!PIR1bits.TX1IF); //Wait for empty buffer.
            TXREG = Text_Int0[i];
        }

        while (!PIR1bits.TX1IF); //Wait for empty buffer.
        TXREG = 0x0D; //Send command to TXREG buffer the ASCII character \r (Return to Home).


    } else if (INTCON3bits.INT2F) { //Test if there is a change in the port. 

        INTCON3bits.INT2F = 0; //Clean the flag interrupt. 
        Counter_Button2++; //Increment the counter every single state change.

        sprintf(Text_Int2, "INT2 Counter: %d", Counter_Button2);

        for (int i = 0; i < strlen(Text_Int2); i++) {

            while (!PIR1bits.TX1IF); //Wait for empty buffer.
            TXREG = Text_Int2[i];
        }

        while (!PIR1bits.TX1IF); //Wait for empty buffer.
        TXREG = 0x0D; //Send command to TXREG buffer the ASCII character \r (Return to Home).

    }

}

