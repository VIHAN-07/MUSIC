#include <xc.h>

int arr[4] = {2, 5, 1, 6};
int ch;

void sort_ascending(int arr[]) {
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sort_descending(int arr[]) {
    for (int i = 0; i < 4 - 1; i++) {
        for (int j = 0; j < 4 - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main(void) {
    TRISE = 0x01;

    while (1) {
        ch = (int)LATE;
        switch (ch) {
            case 1:
                sort_ascending(arr);
                break;
            case 2:
                sort_descending(arr);
                break;
        }

        TRISA = 0x00;
        TRISB = 0x00;
        TRISC = 0x00;
        TRISD = 0x00;

        PORTA = arr[0];
        PORTB = arr[1];
        PORTC = arr[2];
        PORTD = arr[3];
    }
    return;
}
