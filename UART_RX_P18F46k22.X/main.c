/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on January 16, 2024, 12:03 PM
 */


#include <xc.h> //Libaray to use Microchip Microcontrollers. 
#include "Fuses_Set.h" //Library to set fuses. 
//Instructions or commands of the LCD 
#define CLR 0x01 //Command to clear the LCD. 
#define RH 0x02 //Command to Return to Home that is the first position of the LCD (inside first raw and column).
#define EMS 0x06 //Command Entry Mode Set to use moving direction cursor. 
#define DC 0x0F //Command Display Control to set display, cursor and blink. 
#define DSR 0x1C //Command to control the cursor shift to Right (Display Shift Right).
#define DSL 0x18 //Command to control the cursor shift to Left (Display Shift Left). 
#define FS 0x28 //Command to control the 4(28)/8(38) bits mode, 5x8/5x11 character, 1/2 lines display.
#define ROW1 0X80 //Command to access the address of row 1. 
#define ROW2 0xC0 //Command to access the address of row 2. 
#define ROW3 0X94 //Command to access the address of row 3. 
#define ROW4 0XD4 //Command to access the address of row 4. 
#define Set 0 //Command to configuration an instruction. 
#define Write 1 //Command to write on the LCD. 
//Pins of the LCD 
#define RS LATCbits.LATC4 //Define pin (RC4) Register Select as bit flag.
#define EN LATCbits.LATC5 //Define pin (RC5) Enable as bit flag.  

//Prototype functions. 
void Configurations (void);
void LCD_Init (void);


void main(void) {
    
    //Call functions. 
    Configurations(); 
    
    while(1){
        
    }
    
}

//Develop function.
void Configurations (void){
    
    OSCCON = 0x72; //Internal oscillator and frequency. 
    
    //Set ports C & D as digital ports. 
    ANSELCbits.ANSC4 = 0; 
    ANSELCbits.ANSC5 = 0; 
    
    ANSELD = 0x00; 
    
    //Set ports C & D as outputs. 
    TRISCbits.RC4 = 0; 
    TRISCbits.RC5 = 0; 
    
    TRISD = 0x00; 
    
    //Clean the ports. 
    LATCbits.LC4 = 0; 
    LATCbits.LC5 = 0; 
    
    LATD = 0; 
    
}

void LCD_Init (void){
    
    __delay_ms(30);
    
}