#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0)
    {
        return false;
    }
    int m = x;
    long num = 0;
    while (m != 0)
    {
        num *= 10;
        num += m % 10;
        m /= 10;
    }
    if (x == num)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int x = 0;
    scanf("%d", &x);

    printf("%d", isPalindrome(x));

    return 0;
}