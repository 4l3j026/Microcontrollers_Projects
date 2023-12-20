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
void Configuration(void);
void Set_Instruction(unsigned char S_Instruction);
void Write_Instruction(unsigned char W_Instruction);
void LCD_Instructions(unsigned char Instruction);
void __interrupt INT(void);
//Constants to use the display. 
#define RS 0x00 
#define RH 0x02
#define CD 
#define RS 

//Main function. 

void main(void) {

    //Call functions. 
    Configuration();

    //Infinite Loop. 
    while (1) {



    }

}

//Develop configuration functions. 

void Configuration(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set all ports as digital. 

    TRISBbits.RB0 = 1; //Set the pin 0 from the port B as input. 
    TRISD = 0x00; //Set port D as outputs. 
    TRISE = 0x00; //Set port E as outputs. 

    //Interrupts configurations. 
    RCONbits.IPEN = 0;
    INTCONbits.GIE = 0;
    INTCONbits.INT0E = 1;
    INTCONbits.INT0IF = 0;
    INTCON2bits.INTEDG0 = 0;

    //LCD configurations. 


}

//Develop 

void Set_Instruction(unsigned char S_Instruction) {



}

//Develop

void Write_Instruction(unsigned char W_Instruction) {



}

//Develop 

void LCD_Intructiions(unsigned char Instruction) {

    
    
}