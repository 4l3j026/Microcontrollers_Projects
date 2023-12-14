/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on December 13, 2023, 4:43 AM
 */


#include <xc.h>
#include <pic18f4550.h> //Microchip Microcontrollers library to use registers and some functions. 
#include "Fuses.h" //Library created to set fuses from microcontroller. 
//LCD Constants. 
#define CD 0x01 //Constant to use the Clear Display.
#define RH 0x02 //Constant to use the Return Home. 
#define EMS 0x06 //Constant to use the Entry Mode. 
#define DC 0x0F //Constant to use the Display Control. 
#define DSR 0x1C //Constant to control the cursor shift to Right (Display Shift Right).
#define DSL 0x18 //Constant to control the cursosr shift to Left (Display Shift Left). 
#define FS 0x38 //Constant to Function Set.
#define RAW1 0x80 //Constant to print inside first raw. 
#define RAW2 0xC0 //Constant to print inside second raw. 
#define RS LATE0 //Constanto to send data to Register Select.
#define E LATE1 //Constant to send data to Enable. 

//Prototype functions. 
void Configuration(void); //Function to set some registers, outputs, internal oscillator. 
void Configuration_LCD(unsigned char Set); //Function to set the LCD. 
void LCD(unsigned char Data);
void Write(unsigned char Data_W);
void __interrupt() INT(void); //Declare the interrupt function. 

//Main function. 

void main(void) {

    //Call Configuration function. 
    Configuration();

    while (1) { //Infinite loop. 



    }

    return;
}

//Develop function of configuration. 

void Configuration(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    TRISBbits.RB0 = 1; //Set the pin 0 from the port B. 
    TRISD = 0x00; //Set all pins of the port D as outputs. 
    TRISE = 0x00; //Set all pins of the por E as outputs. 

    //Set interrupts.
    RCONbits.IPEN = 0; //Interrupt priority disabled. 
    INTCONbits.GIE = 1; //Global interrupt enable. 
    INTCONbits.INT0E = 1; //Interrupt 0 enable. 
    INTCONbits.INT0F = 0; //Interrupt 0 flag cleared. 
    INTCON2bits.INTEDG0 = 0; //Interrupt falling edge. 

    //Set LCD. 
    Configuration_LCD(EMS);
    Configuration_LCD(DC);
    Configuration_LCD(FS);

}

//Develop function of LCD. 

void Configuration_LCD(unsigned char Set) {

    RS = 0; //Value to set LCD on this Register Select. 
    LCD(Set);

}

void Write(unsigned char Data_W) {

    RS = 1; 
    LCD(Data_W);

}

void LCD(unsigned char Data) {

    E = 1;
    __delay_ms(15);
    LATD = Data;
    __delay_ms(10);
    E = 0;
    __delay_ms(10);

}

void __interrupt() INT(void) {

    if (INT0IF) {
        INTCONbits.INT0IF = 0;

    }

}
