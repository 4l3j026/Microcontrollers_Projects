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


//Main function. 

void main(void) {

    Config_Reg(); //Call function. 

    while (1) {

    }
}

//Develop function to config registers of PIC. 

void Config_Reg(void) {

    
    
}
