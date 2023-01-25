#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    long a, b;
    long n = 0;
    scanf("%ld %ld", &a, &b);
    if (b == 0)
    {
        printf("%ld", a * a);
    }
    else
    {
        {
            for (long i = b; i <= a; i++)
            {
                n += (i - b) * (a / i);
                if (a % i >= b)
                {
                    n += a % i - b + 1;
                }
            }
            printf("%ld", n);
        }
    }
    return 0;
}