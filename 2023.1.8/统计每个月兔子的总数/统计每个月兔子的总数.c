#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{

    int month = 0;
    while (scanf("%d", &month) != EOF)
    {
        int a[3] = { 1,1,0 };
        if (month == 1 || month == 2)
        {
            printf("%d\n", 1);
        }
        while (month > 2)
        {
            a[2] = a[0] + a[1];
            a[0] = a[1];
            a[1] = a[2];
            month--;
        }
        printf("%d\n", a[2]);
    }
    return 0;
}