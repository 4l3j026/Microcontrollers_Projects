/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on December 13, 2023, 4:43 AM
 */

/*
        Project Description: Using the LCD display 16x2, show inside raw 1 and raw 2 characters
        when press the button interrupt, also, the display have to set in 8 bits. 
 */


#include <xc.h>
#include <pic18f4550.h> //Microchip Microcontrollers library to use registers and some functions. 
#include <string.h> //Library to use strlen function. 
#include "Fuses.h" //Library created to set fuses from microcontroller.
//LCD Constants. 
#define CD 0x01 //Constant to use the Clear Display.
#define RH 0x02 //Constant to use the Return Home. 
#define EMS 0x06 //Constant to use the Entry Mode. 
#define DC 0x0F //Constant to use the Display Control. 
#define DSR 0x1C //Constant to control the cursor shift to Right (Display Shift Right).
#define DSL 0x18 //Constant to control the cursosr shift to Left (Display Shift Left). 
#define FS 0x38 //Constant to Function Set.
#define RAW1 0x80 //Constant to print inside first raw trough address of the LCD. 
#define RAW2 0xC0 //Constant to print inside second raw trough address of the LCD. 
#define RS LATE0 //Constanto to activate the Register Select.
#define E LATE1 //Constant to activate the Enable. 

//Prototype functions. 
void Configuration(void); //Function to set some registers, outputs, internal oscillator. 
void Configuration_LCD(unsigned char Set); //Function to set the LCD. 
void LCD(unsigned char Data);
void Write(unsigned char Data_W);
void __interrupt() INT(void); //Declare the interrupt function. 

//Variables
char Texto1[8] = {"Hello!"};
char Texto2[16] = {"I love you!"};

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
    Configuration_LCD(CD);

}

//Develop function of LCD. 

void Configuration_LCD(unsigned char Set) {

    RS = 0; //Value to set LCD on this Register Select. 
    LCD(Set);

}

void Write(unsigned char Data_W) {

    RS = 1; //Value to write on the LCD. 
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

    if (INT0IF) { //Test if the flag has been activated. 

        INTCONbits.INT0IF = 0; //Clean the flag.

        Configuration_LCD(RAW1 + 4); //Select the raw for write. 

        for (unsigned char i = 0; i < strlen(Texto1); i++) {
            Write(Texto1[i]);
        }

        Configuration_LCD(RAW2 + 1);

        for (unsigned char i = 0; i < strlen(Texto2); i++) {
            Write(Texto2[i]);
        }
        

    }

}
