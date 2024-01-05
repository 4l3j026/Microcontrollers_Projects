/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on December 14, 2023, 3:30 AM
 */


#include <xc.h> //Microchip Microcontrollers library to use registers and some functions.
#include <pic18f4550.h> //Microchip Microcontrollers library to use registers and some functions. 
#include <string.h> //Library to use strlen function. 
#include "Fuses.h" //Library created to set fuses from microcontroller.
//Prototype functions. 
void Configuration(void); //Function to set some registers of the microcontroller. 
void Set_Instruction(unsigned char S_Instruction);
void Write_Instruction(unsigned char W_Instruction);
void LCD_Instructions(unsigned char Instruction);
void Test(void);
void __interrupt() INT(void); //Interrupt function without priority. 
//Constants to use the display. 
#define CD 0x01 //Command to Clear Display.
#define RH 0x02 //Command to Return to Home that is the first position of the LCD (inside first raw and column).
#define EMS 0x06 //Command Entry Mode Set to use moving direction cursor. 
#define DC 0x0F //Command Display Control to set display, cursor and blink. 
#define DSR 0x1C //Command to control the cursor shift to Right (Display Shift Right).
#define DSL 0x18 //Command to control the cursor shift to Left (Display Shift Left). 
#define FS 0x28 //Command to control the 4/8 bits mode, 5x8/5x11 character, 1/2 lines display. 
#define ROW1 0x80 //Command to use the first line of the LCD, ROW 1.
#define ROW2 0xC0 //Command to use the second line of the LCD, ROW2. 
#define RS LATE0 //Register select on pin LE0.
#define E LATE1 //Enable on pin LE1. 

//Variables 
char Text1 [20] = {"Hello!"}; //Variable to show on first row of the LCD.
char Text2 [26] = {"Everyone!"}; //Variable to show on the second row of the LCD. 

//Main function. 
void main(void) {

    //Call functions. 
    Configuration();
    Test();
    //Infinite Loop. 
    while (1) {



    }

}

//Develop configuration function. 

void Configuration(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set all ports as digital. 

    TRISBbits.RB0 = 1; //Set the pin 0 from the port B as input. 
    TRISD = 0x00; //Set port D as outputs. 
    TRISE = 0x00; //Set port E as outputs. 

    //Interrupts configurations. 
    RCONbits.IPEN = 0; //Interrupt Priority Enable disable. 
    INTCONbits.GIE = 1; //Global Interrupt Enable activated. 
    INTCONbits.INT0E = 1; //Interrupt 0 Enable activated. 
    INTCONbits.INT0IF = 0; //Clean the Interrupt Flag. 
    INTCON2bits.INTEDG0 = 0; //Interrupt Edge (falling).

    //LCD configurations. 
    Set_Instruction(0x02);
    Set_Instruction(EMS);
    Set_Instruction(DC);
    Set_Instruction(FS);
    Set_Instruction(CD);

}

//Develop 
void Set_Instruction(unsigned char S_Instruction) {

    RS = 0;
    LCD_Instructions(S_Instruction >> 4);
    LCD_Instructions(S_Instruction & 0x0F);

}

//Develop

void Write_Instruction(unsigned char W_Instruction) {

    RS = 1;
    LCD_Instructions(W_Instruction >> 4);
    LCD_Instructions(W_Instruction & 0x0F);

}

//Develop 

void LCD_Instructions(unsigned char Instruction) {

    E = 1;
    __delay_ms(15);
    LATD = Instruction;
    __delay_ms(15);
    E = 0;
    __delay_ms(15);

}

//Function to show data on LCD. 
void Test(void) {

    Set_Instruction(ROW1);

    for (int i = 0; i < strlen(Text1); i++) {

        Write_Instruction(Text1[i]);

    }

    __delay_ms(100);
    
    Set_Instruction(ROW2);

    for (int j = 0; j < strlen(Text2); j++) {

        Write_Instruction(Text2[j]);

    }

}


