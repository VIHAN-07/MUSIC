#include<xc.h>

int arr[4]={5,2,6,8};
int ch;

int ascending(const void *a,const void *b)
{
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return (int_a-int_b);
}

int descending(const void *a, const void *b)
{
    int int_a = *(int*)a;
    int int_b = *(int*)b;
    return(int_b-int_a);
}

void main(void)
{   
    TRISE = 0x01;
    ch=LATE;
    switch(ch)
    {
        case 1:
            qsort(arr,4,sizeof(int),ascending);
            break;
        case 2:
            qsort(arr,4,sizeof(int),descending);
            break;
    }
}