#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int convertInteger(int A, int B) 
{
    unsigned int m = A ^ B;
    int n = 0;

    while (m != 0)
    {
        m &= (m - 1);
        n++;
    }
    return n;
}

int main()
{

    int a = 29, b = 15;

    printf("%d ", convertInteger(a, b));

    return 0;
}