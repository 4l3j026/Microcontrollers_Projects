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


#include <xc.h> //Microchip Microcontrollers library to use registers and some functions.
#include <pic18f4550.h> //Microchip Microcontrollers library to use registers and some functions. 
#include <string.h> //Library to use strlen function. 
#include "Fuses.h" //Library created to set fuses from microcontroller.
//LCD Constants Address to set some features. 
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
void Set_LCD_Enable(unsigned char Instruction); //Function to set LCD.  
void Instruction_LCD(unsigned char Data); //Function to delays and 
void Write_LCD_Enable(unsigned char Data_Write);
void __interrupt() INT(void); //Declare the interrupt function. 

//Variables to show on the display. 
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

    //LCD registers configuration to initialize the display. 
    Set_LCD_Enable(EMS); //Set the shift display. 
    Set_LCD_Enable(DC); //Set entire display, turn on the cursor. 
    Set_LCD_Enable(FS); //Set the display to use two raws and 8 bits configuration. 

}

//Develop set function of LCD to send Address Configuration

void Set_LCD_Enable(unsigned char Instruction) {

    RS = 0; //Register Select value in High to set LCD on this . 
    Instruction_LCD(Instruction); //Call function

}

//Develop write function to show data on LCD display. 

void Write_LCD_Enable(unsigned char Data_Write) {

    RS = 1; //Value to write on the LCD. 
    Instruction_LCD(Data_Write); //Call function. 

}

void Instruction_LCD(unsigned char Data) {

    __delay_ms(15); //Delay to stabilize the voltages. 
    E = 1; //Enable activated to use the LCD. 
    __delay_ms(15); //Delay to stabilize the data.  
    LATD = Data; //Assign to port the data to write data, or to set data. 
    __delay_ms(10); //Delay to stabilize the data. 
    E = 0; //Enable disabled to of the LCD. 
    __delay_ms(10); //Delay to stabilize the instruction. 

}

//Develop interrupt function. 

void __interrupt() INT(void) {

    if (INT0IF) { //Test if the flag has been activated. 

        INTCONbits.INT0IF = 0; //Clean the flag.

        Set_LCD_Enable(RAW1 + 4); //Select the raw 1 for write and plus 4 positions. 

        for (unsigned char i = 0; i < strlen(Texto1); i++) { //For loop from 0 to vector size to show each character. 

            Write_LCD_Enable(Texto1[i]); //Instruction to write on the display.  

        }

        Set_LCD_Enable(RAW2 + 1); //Select the raw 2 for write and plus one position.

        for (unsigned char i = 0; i < strlen(Texto2); i++) { //For loop from 0 to vector size to show each character.

            Write_LCD_Enable(Texto2[i]); //Instruction to write on the display. 

        }

    }

}
