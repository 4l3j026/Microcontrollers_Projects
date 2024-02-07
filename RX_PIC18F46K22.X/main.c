/*
 * File:   main.c
 * Author: Alejo
 *
 * Created on February 2, 2024, 11:05 PM
 */

//Headers
#include <xc.h>
#include <string.h>
#include "Fuses_Configuration.h"

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
void Init_LCD(void); //Function to initialize the LCD. 
void LCD_Instruction(unsigned char Instruction); //Function to send data or instruction inside LCD.
void Send_Instruction_Data(unsigned char Instruction, unsigned char Data); //Function to enable or disable RS.

//Variables. 
unsigned char CountRX_Units = 0x30;
unsigned char CountRX_Tens = 0x30;
unsigned char Rx_Text_1 [] = {"Interrupt Counter : "};

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
    //Set pins as outputs. 
    TRISD = 0x00; 
    
    //---- Interrupts Configurations ----
    INTCONbits.GIE = 1; //Global Interrupt Enabled. 
    INTCONbits.PEIE = 1;  //Peripheral Interrupt Enabled. 
    RCONbits.IPEN = 0; //Interrupt Priority disabled. 
    
    PIE1bits.RC1IE = 1; //Receive Enabled. 
    PIR1bits.RC1IF = 0; //Receive Flag cleared. 
    
    //---- EUSART Configurations ----
    SPBRG = 103; //Configuration 9600 bauds. 
    TRISCbits.RC6 = 1; //Enable pin RC6 (TX1).
    TRISCbits.RC7 = 1; //Enable pin RC7 (RX1).

    //---- Transmitter configuration TXSTA1 (TX). 
    TXSTA1bits.TX91 = 0; //9 bits transmitter disabled. 
    TXSTA1bits.TXEN1 = 1; //Transmit Enabled. 
    TXSTA1bits.SYNC1 = 0; //Asynchronous mode. 
    TXSTA1bits.BRGH1 = 1; //High baud rate. 

    //---- Receive configuration RCSTA1 register (RX).
    RCSTAbits.SPEN1 = 1; //Serial port enable bit. 
    RCSTAbits.RX91 = 0; //9 bits transmitter disabled. 
    RCSTAbits.CREN1 = 1; //Receive continuous enabled. 

    //---- Baud configuration BAUDCON1. 
    BAUDCON1bits.BRG16 = 0; //16 bits mode disabled. 

    /*
     
     Remember data buffers. 
     * 
        RCREG1; ----> Receive buffer.
        TXREG1; ----> Transmitter buffer.
      
     */
    
}

void __interrupt () RX_EUSART (void){
    
    if (PIR1bits.RC1IF){
        
        
        
    }
    
}

void Init_LCD(void) {

    __delay_ms(20); //Delay set by the manufacturer. 
    Send_Instruction_Data(Set, 0x30); //Data set by the manufacturer. 
    __delay_ms(5); //Delay set by the manufacturer. 
    Send_Instruction_Data(Set, 0x30); //Data set by the manufacturer. 
    __delay_ms(5); //Delay set by the manufacturer. 
    Send_Instruction_Data(Set, 0x30); //Data set by the manufacturer. 
    Send_Instruction_Data(Set, 0x02); //Data set by the manufacturer. 
    Send_Instruction_Data(Set, EMS);
    Send_Instruction_Data(Set, DC);
    Send_Instruction_Data(Set, FS);
    Send_Instruction_Data(Set, CLR);
    __delay_ms(50); //Delay set by the manufacturer. 

}

//Develop LCD function to send data or instruction. 

void Send_Instruction_Data(unsigned char Instruction, unsigned char Data) {

    RS = Instruction; //Enable or disabled the register select to write data, or send instruction set.
    LCD_Instruction(Data >> 4); //Send first the most significant bits
    LCD_Instruction(Data); //Send the least significant bits. 

}

//Develop LCD instruction.

void LCD_Instruction(unsigned char Instruction) {

    EN = 1; //Pin ENabled. 
    __delay_ms(15); //Wait for the instruction. 
    LATD = Instruction; //Send Instruction to the port. 
    __delay_ms(15); //Wait for the instruction. 
    EN = 0; //Pin disabled.
    __delay_ms(15); //Wait for the instruction. 

}

void LCD_Message (void){
    
    Send_Instruction_Data(Set, ROW1);
    
    for (int i = 0;i < strlen(Rx_Text_1) ; i++){
        
        Send_Instruction_Data(Write, Rx_Text_1[i]); 
        
    }
    
}