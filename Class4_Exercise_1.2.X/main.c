/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 24, 2023, 8:10 PM
 * 
 *      PROJECT DESCRIPTION:
 * 
 *          Now, in this project we�re going to make a bitwise operation 
 *          with high significant bits using all ports, shifting two bits.
 * 
 * 
 */


#include <xc.h> //Compiler libraries. 
#include <pic18f4550.h> //Specific registers of PIC18F4550.
#include "Fuses.h"  //Specific library for set the fuses of PIC.

//Prototype functions. 
void Configuration(void);
void Bitwise(void);

//Global variables. 
int Time = 800;

void main(void) {

    //Call functions.
    Configuration();

    while (1) {

        Bitwise();

    }

}

//Develop function of configuration.

void Configuration() {

    OSCCON = 0x72; //Oscillator controller register. 
    ADCON1 = 0x0F; //Analog and Digital control register. 

    //TRIS registers. 
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    //LAT registers, for initialize the variable. 
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    LATD = 0x00;
    LATE = 0x00;

}

//Develop the exercise 

void Bitwise() {

    //Shift operation in port A. 
    for (int A = 0; A < 6; A++) {
        LATA = (0x03 << A);
        __delay_ms(Time);
    }
    //Shift operation in Port B.
    for (int B = 0; B < 7; B++) {
        LATB = (0x03 << B);
        __delay_ms(Time);
    }
    //Shift operation in Port C.
    for (int C = 0; C < 6; C++) {
        LATC = (0x03 << C);
        __delay_ms(Time);
    }
    //Shift operation in port D.
    for (int D = 0; D < 7; D++) {
        LATD = (0x03 << D);
        __delay_ms(Time);
    }
    //Shift operation in Port E.
    for (int E = 0; E < 3; E++) {
        LATE = (0x01 << E);
        __delay_ms(Time);
    }

}