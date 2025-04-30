#include <xc.h>
#include <pic18f4550.h>

#pragma config FOSC = HS 
#pragma config WDT = OFF       
#pragma config LVP = OFF        
#pragma config BOR = OFF        

#define _XTAL_FREQ 8000000      
#define RELAY_TRIS  TRISAbits.TRISA4
#define RELAY_LAT  LATAbits.LATA4
#define INT1_PIN  TRISBbits.TRISB1

unsigned char relay_flag = 0;

void t_relay(){
	relay_flag = relay_flag ? 0 : 1 ;
	RELAY_LAT = relay_flag;
}

void setup_int(){
    INT1_PIN  = 1; 
    INTCON2bits.INTEDG1 = 0; 
    INTCON3bits.INT1IF = 0; 
    INTCON3bits.INT1IE = 1;
    GIE = 1;                
    PEIE = 1;            
}


void setup_relay(){
    RELAY_TRIS = 0;  
    RELAY_LAT = 0;   
}

void __interrupt() handle_interrupts() {
    if (INTCON3bits.INT1IF) { 
	t_relay();
        INTCON3bits.INT1IF = 0;    
    }
}

void main(void){
    setup_relay();
    setup_int();
    
    while(1){
        
    }
}
