#include<stdio.h>

#define CHANGE(a) ((a & 0xaaaaaaaa) >> 1) ^ ((a & 0x55555555) << 1)

int main ()
{
    int a = 10;
    
    printf("%d\n",CHANGE(a));

    return 0;
}