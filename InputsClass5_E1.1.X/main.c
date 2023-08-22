/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on August 21, 2023, 5:50 PM
 */

/*
        Project Description: 
 *          This project show the use of digital inputs reading the pin with 
 *          PORT register. 
 *          So with two buttons turn on two leds, sets as pull-up and pull down. 
 */

//Adding Libraries 
#include <xc.h> //Library to microchip microcontrollers. 
#include "Fuses.h" //Personal Library to set fuses. 
#include <pic18f4550.h> //Library to PIC18F4550.

//Prototype functions.
void Configurations (void);


struct Variables {
        
    
    
}Led_1, Led_2;

//Main function. 
void main(void) {
    
    //Call functions.
    Configurations();
    
    //Infinite loop
    while(1){
        
    } 
    
    
}

//Development function about configurations registers. 
void Configurations (){
    
    //OSCillator CONtroller.
    OSCCON = 0x72; 
    //Analog & Digital CONtroller.
    ADCON1 = 0x0F;
    
    //Set pin RB0 & RB1 as input.
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1; 
    //Set pin RB2 & RB3 as output.
    TRISBbits.RB2 = 0; 
    TRISBbits.RB3 = 0; 
    
    //Set RB2 & RB3 as low logic state. 
    LATBbits.LB2 = 0;
    LATBbits.LB3 = 0; 
    
}

