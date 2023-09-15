/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 12, 2023, 6:40 PM
 */


#include <xc.h> //Library to Microchip microcontrollers. 
#include "Fuses.h" //Library to set fuses of PIC. 

//Prototype functions. 
void Conf_Reg(void);


//Main function

void main(void) {

    //Call function. 
    Conf_Reg();
    //Infinite Cycle. 
    while (1) {

    }

}

//Developing function.

void Conf_Reg(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    TRISD = 0x00; //Set ports RB as outputs.
    TRISE = 0x00; //Set ports RE as outputs.

    TRISB = 0x03; //Set ports RB0 and RB1 as digital inputs. 

}

//Develop function. 


