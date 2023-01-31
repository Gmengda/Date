#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main() {
    int m = 0;
    scanf("%d", &m);
    int i = 0;
    int n = 0;
    int sum = 0;
    while (m)
    {
        n = m & 1;
        sum += n * pow(10, i);
        m /= 10;
        i++;
    }
    printf("%d", sum);
    return 0;
}