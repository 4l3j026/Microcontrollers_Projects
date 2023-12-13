/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on December 13, 2023, 4:43 AM
 */


#include <xc.h> //Microchip Microcontrollers library to use registers and some functions. 
#include "Fuses.h" //Library created to set fuses from microcontroller. 

//Prototype functions. 
void Configuration(void);

//Main function. 

void main(void) {
    
    //Call Configuration function. 
    Configuration(); 

    while (1) { //Infinite loop. 



    }

    return;
}

//Develop function of configuration. 
void Configuration (void){
    
    OSCCON = 0x72; //
    ADCON1 = 0x0F; 
    
    
    
}
