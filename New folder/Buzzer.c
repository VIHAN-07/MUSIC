#include <stdio.h>
#include <stdlib.h>
#include<xc.h>

#define _XTAL_FREQ 48000000
volatile int count=0;

void inittimer1() {
    T1CON = 0b00110000;     // Prescaler 1:8, Timer1 OFF
    TMR1H = 0x00;
    TMR1L = 0x00;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIR1bits.TMR1IF = 0;    // Clear flag
    T1CONbits.TMR1ON = 1;   // Start timer
    PIE1bits.TMR1IE=1;
}


void __interrupt() ISR(){
    if(PIR1bits.TMR1IF){
        PIR1bits.TMR1IF = 0;
        TMR1H = 0x00;
        TMR1L = 0x00;
        count++;
        if(count==100){
            LATAbits.LATA5 = ~LATAbits.LATA5;  
            count=0;
        }    
    }    
}

int main() {
    TRISAbits.TRISA5 = 0;    // Output pin
    LATAbits.LATA5 = 1;
    inittimer1();
    while (1);
      
}

