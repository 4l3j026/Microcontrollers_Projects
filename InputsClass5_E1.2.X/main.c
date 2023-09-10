/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 9, 2023, 3:40 PM
 * 
 *      Project Description: 
 *          Using one button, change the led state press one time. 
 */


#include <xc.h> //Library to microchip microcontrollers. 
#include "Fuses.h"  //Library created to set fuses. 
#include <pic18f4550.h> //Library to 

//Prototype Functions. 
void Set_Registers(void);
void Led_State(void);

void main(void) { //Main function. 

    Set_Registers(); //Call function. 

    while (1) { //Infinite Cycle. 

        Led_State(); //Call function. 

    }

}

//Develop function of PÏC registers. 

void Set_Registers() {

    OSCCON = 0x72; //Internal Oscillator and frequency of 8MHz. 
    ADCON1 = 0x0F; //Set all pins as digital.

    TRISBbits.RB0 = 1; //Set pin RB0 as input. 
    TRISBbits.RB2 = 0; //Set pin RB2 as output. 

    LATAbits.LA1 = 0; //Assign low state on pin. 

}

//Develop function of the led state. 

void Led_State() {

    if (PORTBbits.RB0 == 1) {

        while (PORTBbits.RB0 == 1) {

            __delay_ms(20); //Delay to switch bounce. 
            LATBbits.LB2 = !LATBbits.LB2; //Change the last state of port. 

        }

    }

}
