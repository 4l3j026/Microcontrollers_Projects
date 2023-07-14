/* 
 * File:   
 * Author: Daniel Alejandro Reyes León 
 * Comments: This is a simple test about libraries. 
 * Revision history: 
 */
// Configuration of some important fuses. 
/*
 * This statement refer to set speed of internal oscillator
 * Frequency OSCillator (FOSC) = Use INTernal OSCillator in High Speed (INTOSC_HS) 
 * In this microcontroller High Speed is from > 4 Mhz 
 */
#pragma config FOSC = INTOSC_HS //  -------------?
/*
 * This pragma configuration use to power off the "Watch Dog Timer" 
 * Because we don't need restart the microcontroller after some time. 
 */
#pragma config WDT = OFF //  -------------?
/*
 * This pragma configuration use to power off the "Low Voltage Programming"
 * Because we don't need take the high state as 3.3V but as 5V. 
 */
#pragma config LVP = OFF //  -------------?

//Define time delays
/*
 * This is a function by library <xc.h> for calculate of delays. 
 * So we're programming the maximum speed of internal oscillator (Wich is 8Mhz).  
 */
#define _XTAL_FREQ 8000000  //  -------------?
// This is a guard condition so that contents of this file are not included
// more than once.  

#include <xc.h> // include processor files - each processor file is guarded.  



