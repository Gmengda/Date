#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
            digits[i] = 0;
        else
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
    }
    *returnSize = digitsSize + 1;
    int* ret = (int*)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, sizeof(int) * (digitsSize + 1));
    ret[0] = 1;
    return ret;
}

int main()
{
    int m[100];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m[i]);
    }
    plusOne(m, n, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d", m[i]);
    }

    return 0;
}