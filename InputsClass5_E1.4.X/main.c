/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 12, 2023, 6:40 PM
 */
/*
 Project Description: 
 * 
 */

#include <xc.h> //Library to Microchip microcontrollers. 
#include "Fuses.h" //Library to set fuses of PIC. 

//Prototype functions. 
void Conf_Reg(void);
void Counter(void);

//Global variables. 
int Counter_Pull_Down = 0;
int Counter_Pull_Up = 0;

//Main function

void main(void) {

    //Call function. 
    Conf_Reg();
    //Infinite Cycle. 
    while (1) {

        Counter();

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

void Counter(void) {

    if (!PORTBbits.RB0) {

        __delay_ms(100);
        Counter_Pull_Down++;
        LATD = Counter_Pull_Down;
        while(!PORTBbits.RB0);
        LATBbits.LATB0 = !LATBbits.LATB0;

    }

}

