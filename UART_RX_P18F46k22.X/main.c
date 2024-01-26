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
void Configurations(void);
void LCD_Init(void);
void LCD_Set_Write(unsigned char WR_SE, unsigned char Command);
void LCD_Data_Instruction(unsigned char Data);

void main(void) {

    //Call functions. 
    Configurations();
    LCD_Init();

    while (1) {

    }

}

//Develop function.

void Configurations(void) {

    OSCCON = 0x72; //Internal oscillator and frequency. 

    //Set ports C & D as digital ports (0). 
    ANSELCbits.ANSC4 = 0;
    ANSELCbits.ANSC5 = 0;
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;

    ANSELD = 0x00;

    //Set ports C & D as outputs. 
    TRISCbits.RC4 = 0;
    TRISCbits.RC5 = 0;

    TRISD = 0x00;

    //Clean the ports. 
    LATCbits.LC4 = 0;
    LATCbits.LC5 = 0;

    LATD = 0;

    //---- EUSART configuration ----

    //RCSTAx is a status and control receive register. 
    TXSTA1bits.SYNC = 0; //Asynchronous mode. 
    RCSTA1bits.SPEN = 1; //Serial port enable bit. (Is not necessary set RC6TX, TC7RX)
    RCSTA1bits.CREN = 1; //Asynchronous receive mode enabled. 
    

}

//Develop function to initialize LCD. 

void LCD_Init(void) {

    __delay_ms(20); //Delay set by the manufacturer. 
    LCD_Set_Write(Set, 0x30); //Data set by the manufacturer. 
    __delay_ms(5); //Delay set by the manufacturer. 
    LCD_Set_Write(Set, 0x30); //Data set by the manufacturer. 
    __delay_ms(5); //Delay set by the manufacturer. 
    LCD_Set_Write(Set, 0x30); //Data set by the manufacturer. 
    LCD_Set_Write(Set, 0x02); //Data set by the manufacturer. (Works using Nibbles send first most significant bits, after the least significant bits.) 
    LCD_Set_Write(Set, EMS);
    LCD_Set_Write(Set, DC);
    LCD_Set_Write(Set, FS);
    LCD_Set_Write(Set, CLR);
    __delay_ms(5); //Delay set by the manufacturer.

}

//Develop function. 

void LCD_Set_Write(unsigned char WR_SE, unsigned char Command) {

    RS = WR_SE; //Register Select to write or set. 
    LCD_Data_Instruction(Command >> 4); //Send the most significant bits. 
    LCD_Data_Instruction(Command); //Send the least significant bits. 

}

//Develop function. 

void LCD_Data_Instruction(unsigned char Data) {

    EN = 1;
    __delay_ms(15); //Wait for instruction. 
    LATD = Data;
    __delay_ms(15); //Wait for instruction.
    EN = 0;
    __delay_ms(15); //Wait for instruction.

}

void __interrupt() EUSART_Int_Rx(void) {



}