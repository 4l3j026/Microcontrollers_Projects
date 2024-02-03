/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on February 2, 2024, 11:05 PM
 */


#include <xc.h>
#include <string.h>
#include "Fuses_Configuration.h"

//Prototype functions. 
void Configurations (void); 

//Variables. 

void main(void) {
    
    //Call functions. 
    Configurations(); 
    
    while (1){
        
        
        
    }

}

void Configurations (void){
    
    OSCCON = 0x72; //Set internal oscillator. 
    
    //Set pins as digital. 
    ANSELC = 0x00; 
    ANSELD = 0x00; 
    
}