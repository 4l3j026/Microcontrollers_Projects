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
void Configurations(void);
void Input_Test(void);

//Global variables.
unsigned int Time = 500;
unsigned int Bounce_Time = 100;

//Main function. 

void main(void) {

    //Call functions.
    Configurations();

    //Infinite loop
    while (1) {

        Input_Test(); //Calling function.  

    }


}

//Development function about configurations registers. 

void Configurations() {

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

//Development of the function to read a state in specific port.

void Input_Test() {

    if (PORTBbits.RB0) { //This conditional reads RBO pin. 
        __delay_ms(Bounce_Time); //Use delay function to switch bouncing. 
        LATBbits.LB2 ^= 1; //Change port state. 
        __delay_ms(Time); //Delay of blink led. 

    } else if (PORTBbits.RB1) { //Another conditional to reads RB1 pin. 
        __delay_ms(Bounce_Time); //Use delay function to switch bouncing. 
        LATBbits.LATB3 ^= 1; //Change port state. 
        __delay_ms(Time); //Delay of blink led.         

    }
    /*
     Another conditional of the code, when the user press RB0 and RB1 blink led's each 80ms.
     */
    while (PORTBbits.RB0 == 1 && PORTBbits.RB1 == 1) {
        __delay_ms(Bounce_Time); //Use delay function to switch bouncing. 
        LATBbits.LB2 = 1; //Assign to the ports a high state. 
        LATBbits.LB3 = 1;
        __delay_ms(80); //Wait 80ms. 
        LATBbits.LB2 = 0;
        LATBbits.LATB3 = 0;
        __delay_ms(80);
    }

}

