#include<xc.h>
#define _XTAL_FREQ 48000000
void inittimer()
{
    T1CON=0b00110000;
    TMR1L=0x00;
    TMR1H=0x00;
    TMR1IF=0;
    TMR1IE=1;
    T1CONbits.TMR1ON=1;
}
void main(void){
    inittimer();
    TRISAbits.TRISA5=0;
    LATAbits.LATA5=1;
    int count=0;
    while(1){
        if(TMR1IF){
            TMR1IF=0;
            TMR1L=0x00;
            TMR1H=0x00;
            count++;
            if (count==50){  
                LATAbits.LATA5=~ LATAbits.LATA5;
                count=0;
            }
        }
    }
    return;
}
