#include <pic18f4550.h>
#define RELAY LATAbits.LATA4

void __interrupt() isr() {
    if (INT1F) {
        INT1F = 0;
        RELAY ^= 1;
        for (int i = 0; i < 1000; i++);
    }
}

void main() {
    ADCON1 = 0x0F;
    TRISA4 = 0;
    TRISB1 = 1;
    RELAY = 1;
    INT1IE = 1;
    INTEDG1 = 0;
    GIE = 1;
    while (1);
}
