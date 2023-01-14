#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
////6/28/496/8128
//int main() {
//    int num = 0;
//    int res = 0;
//    while (scanf("%d", &num) != EOF)
//    {
//        if (num >= 8192)
//        {
//            res = 4;
//        }
//        else if (num >= 496)
//        {
//            res = 3;
//        }
//        else if (num >= 28)
//        {
//            res = 2;
//        }
//        else if (num >= 6)
//        {
//            res = 1;
//        }
//        printf("%d\n", res);
//    }
//    return 0;
//}

int zaa(int m)
{
    int a = 0;
    for (int i = 1; i <= m / 2; i++)
    {
        if (m % i == 0)
        {
            a += i;
        }
    }
    return a;
}

int main() {
    int a = 0;
    int b = 0;

    scanf("%d", &a);

    for (int i = 1; i < a; i++)
    {
        if (i == zaa(i))
        {
            b++;
        }
    }
    printf("%d", b);

    return 0;
}