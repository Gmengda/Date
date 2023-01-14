#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int a, b, c;
    int m = 0;

    scanf("%d %d %d", &a, &b, &c);
    while (b != 1)
    {
        
        switch (b - 1)
        {
        case 2:
            m += 28;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            m += 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            m += 30;
            break;
        }
        b--;
    }
    if ((0 == a % 4 && a % 100 != 0) || (0 == a % 400)&&(b > 2))
    {
        m += 1;
    }
    printf("%d", m + c);
    return 0;
}