#include <xc.h>
#include <pic18f4550.h>
#define _XTAL_FREQ 48000000
     
void initPWM(){
    TRISCbits.TRISC2=0;
   
    CCP1CON=0b00001100;
    T2CON=0b000000011;
    PR2=61;
    CCPR1L=6;
    TMR2=0;
    T2CONbits.TMR2ON=1;
    PIR1bits.TMR2IF = 0;
    while (!PIR1bits.TMR2IF);
    
}    
 
void main(void) {
    initPWM();
    while(1){
        __delay_ms(3000);
        CCPR1L=24;
    }    
    return;
}
