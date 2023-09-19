/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 10, 2023, 1:15 PM
 */

/*
    Project Description: 
        Using a 8-position DIP switch as digital inputs when the port state is high
        and turn off the leds when the port state is low. 
        
 */

#include <xc.h> //Library to microchip microcontrollers. 
#include "Fuses.h" //Library created to set the fuses. 

//Prototype functions. 
void Config_Reg(void);
void Leds_On(void);


//Main function. 

void main(void) {

    Config_Reg(); //Call function. 

    while (1) {
        
        Leds_On(); //Call function. 
        
    }
}

//Develop function to config registers of PIC. 

void Config_Reg(void) {

    OSCCON = 0x72; //Set internal frequency of the PIC.
    ADCON1 = 0x0F; //Set all ports as digital. 

    //Set port B and A as outputs. 
    TRISB = 0x00;
    TRISA = 0x00;
    //Set port C and D as inputs. 
    TRISC = 0xFF;
    TRISD = 0x07;

}

//Develop functions of leds on. 

void Leds_On() {

    LATB = PORTD; 
    LATA = PORTC;

}