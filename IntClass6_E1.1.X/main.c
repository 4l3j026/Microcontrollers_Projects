/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on September 15, 2023, 12:45 AM
 * 
 *      Project Description: 
 *          Here we are using the interruptions of the microcontroller through 
 *          the some registers, RCON, INTCON for understand the idea. 
 *          While blink one led counter increases and show the led bar. 
 */



#include <xc.h>
#include <pic18f4550.h> //Library to Microchip microcontrollers. 
#include "Fuses.h" //Library to set fuses of PIC. 

//Constants 
#define Bounce_Time 100


//Prototype functions. 
void Conf_Reg(void);
void Led(void);
void __interrupt() INT(void); //Interrupt Function Statement. (Without priority)

//Variables
unsigned char Counter = 0;

//Main function

void main(void) {

    //Call function. 
    Conf_Reg();
    //Infinite Cycle. 
    while (1) {

        Led();

    }

}

//Developing function.

void Conf_Reg(void) {

    OSCCON = 0x72; //Set internal oscillator. 
    ADCON1 = 0x0F; //Set ports as digital. 

    TRISD = 0x00; //Set ports RB as outputs.
    TRISE = 0x00; //Set ports RE as outputs.

    TRISB = 0x03; //Set ports RB0 and RB1 as digital inputs. 

    //Interrupts Configuration.

    /*
       Here, we can see how to set specific bit of RCON (Reset CONtrol register). 
       and means Interrupt Priority ENable bit (Disabled). 
     */
    RCONbits.IPEN = 0;

    /*
        Here, on the INTCON (INTerrupt CONtrol Register) I set all bits of the register
        but really is not necessary set all. You can use the previous way (INTCONbits."Specific_Bit").
     */
    INTCON = 0x90; //0b10010000
    //INTCONbits.GIE = 1; 
    /*
        Now, I�m going to set each bit separately of INTCON2.
     */
    INTCON2bits.RBPU = 0; //Pull up internal resistors disable.
    INTCON2bits.INTEDG0 = 0; //Set the interrupt rising (1) or falling (0) edge. 
    INTCON2bits.INTEDG1 = 1; //Set the interrupt rising edge.

    //External interrupt 0 set. 
    INTCONbits.INT0E = 1;
    INTCONbits.INT0F = 0;

    //External interrupt 1 set. 
    INTCON3bits.INT1E = 1;
    INTCON3bits.INT1F = 0;

    /*
        Another way of set specific bits of the register is this, 
        only write the name of the bit, however I'm really prefer 
        the previous form. 

        GIE = 1; //Global Interrupt Enable. 
        INT0E = 0; //Interrupt of port RB0 Enable. 
        INT0F = 0; //Interrupt flag. 
        INTEDG0 = 0; //Falling edge.
     */

}

//Develop function. 

void __interrupt() INT(void) {

    if (INT0IF) {
        __delay_ms(Bounce_Time); //Anti-Bounce time to stabilize the state. 
        INT0IF = 0; //Clean the flag. 
        LATD = Counter++; //Increment the counter. 

    }

}

//Develop function. 

void Led(void) {

    LATEbits.LATE0 ^= 1;
    __delay_ms(500);

}
