#include <xc.h>
#define _XTAL_FREQ 48000000
volatile int count=0;
void inittimer1() {
    T1CON = 0b00110000;     // Prescaler 1:8, Timer1 OFF
    TMR1H = 0x00;
    TMR1L = 0x00;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    PIE1bits.TMR1IE=1;
    PIR1bits.TMR1IF = 0;    // Clear flag
    T1CONbits.TMR1ON = 1;   // Start timer
    
}


void __interrupt() ISR(){
    
    if(PIR1bits.TMR1IF){
        PIR1bits.TMR1IF = 0;
        TMR1H = 0x00;
        TMR1L = 0x00;
        count++;
        if(count==100){
            LATCbits.LATC1 = ~LATCbits.LATC1;  
            count=0;
        }    
    }    
}

int main() {
    TRISCbits.TRISC1 = 0;    // Output pin
    LATCbits.LATC1 = 0;

    inittimer1();
    while (1);
      
}









#include <xc.h>

// Configuration bits (you should configure these based on your setup)
#pragma config FOSC = HS        // High-Speed Oscillator
#pragma config WDT = OFF        // Watchdog Timer disabled
#pragma config LVP = OFF        // Low-Voltage Programming disabled

#define _XTAL_FREQ 8000000     // Define your crystal frequency (adjust as needed)

void main(void)
{
    TRISB = 0x00;               // Set PORTB as output
    LATB = 0xFF;                // Set all PORTB pins high

    while(1)
    {
        LATB = ~LATB;          // Toggle PORTB
        __delay_ms(200);       // Built-in delay function
    }
}










#include <pic18f4550.h>

void delay(unsigned int time)
{
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 5000; j++);
}

void main(void)
{
    TRISB = 0x00;   // Set PORTB as output
    LATB = 0x00;    // Turn all LEDs OFF

    while(1)
    {
        unsigned char i;
        for(i = 0; i < 8; i++)
        {
            LATB = 1 << i;   // Turn on one LED at a time
            delay(500);       // Wait for each LED to blink (adjust delay as needed)
        }
    }
}









#include <pic18f4550.h>

void delay(unsigned int time)
{
    unsigned int i,j;
    for(i=0;i<time;i++)
        for(j=0;j<5000;j++);
        
}

void main(void)
{
   TRISB = 0x00;
   LATB = 0xFF;

   while(1)                                //Loop forever;
   {
       LATB = ~LATB;
       delay(200);
   }
}


