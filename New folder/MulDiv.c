#include <xc.h>

void main(void) {
    int ans;
    int x,y;
    TRISA=0xFF;
    TRISB=0xFF;
    TRISE=0xFF;
    TRISC=0x00;
    
    int choice=LATE;
    x=LATA;
    y=LATB;
    switch(choice){
        case 1:
            ans=x*y;
            break;
        case 2:
            ans=x/y;
            break;
    }      
    LATC=ans;
    return;
}
