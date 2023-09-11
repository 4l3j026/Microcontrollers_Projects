/*
 * File:   main.c
 * Author: Alejandro
 *
 * Created on July 24, 2023, 8:10 PM
 * 
 *      PROJECT DESCRIPTION:
 * 
 *          Now, in this project we´re going to make a bitwise operation 
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
void Hard_Bitwise(void);

//Global variables. 
int Time = 400; //Constant time to make the dynamic variable. 

void main(void) {

    //Call functions.
    Configuration();

    while (1) {

        Bitwise();
        //        Hard_Bitwise();

    }

}

//Develop function of configuration.

void Configuration() {

    OSCCON = 0x72; //Oscillator controller register. 
    ADCON1 = 0x0F; //Analog and Digital control register. 

    //TRIS registers set as outputs. 
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

void Hard_Bitwise() {
    /*
     This is another way to make the class exercise, however is long and need more
     lines code.
     */

    //    Shift operation in port A. 
    for (int A = 0; A < 7; A++) {

        if (A == 6) {
            LATB = 0x01;
        }

        LATA = (0x03 << A);
        __delay_ms(Time);

    }

    //    Shift operation in Port B.
    for (int B = 0; B < 8; B++) {

        LATA = 0x00;

        if (B == 7) {
            LATC = 0x01;
        }

        LATB = (0x03 << B);
        __delay_ms(Time);

    }

    //Shift operation in Port C.
    for (int C = 0; C < 7; C++) {

        if (C == 2) {
            LATC = 0x14;
            __delay_ms(Time);
        }

        LATB = 0x00;

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

//Develop function. 

void Bitwise() {

    /*
     Using bitwise operations we can compress the code to some lines. 
     */
    long N1 = 0x00000003;
    int8_t var = 0;
    char c = 'a';

    for (int i = 0; i < 36; i++) {

        LATA = N1;
        LATB = N1 >> 8;
        LATC = N1 >> 16;
        LATD = N1 >> 24;
        LATE = N1 >> 32;
        __delay_ms(Time);
        N1 = N1 << 1;

    }

}