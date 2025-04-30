#include <xc.h>
void main(void) {
    int a[6]={4,2,6,7,4,5};
    int *arr = &a[0];
    int sum=0;
    for(int i=0;i<6;i++){
        sum=sum+*(arr+i);
    }
    return;
}
