#include <xc.h>
#include<pic18f4550.h>
#include<stdio.h>

#define Fosc 48000000UL
void initUART(unsigned int baudrate){
    TRISCbits.RC6=0;
    TRISCbits.RC7=1;
    
    TXSTA=0b00100000;
    RCSTA=0b10010000;
    
    BAUDCON=0b00000000;
    SPBRG=(unsigned char)(Fosc/(64*baudrate))-1;
    
}    
void SendChar(unsigned char data){
    while(TXSTAbits.TRMT==0);
    TXREG=data;
}
void putch(char data){
    SendChar((unsigned char )data);
}
unsigned char GetChar(void){
    while(!PIR1bits.RCIF );
    return RCREG;
}    
void main(void) {
    initUART(9600);
    
    while(1){
        printf("%c!",GetChar());
    }
    while(1);
    return;
}
