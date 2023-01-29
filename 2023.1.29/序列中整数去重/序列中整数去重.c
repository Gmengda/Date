#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n = 0;
    int m[5000];
    int mm[1000];
    int s = 0;
    int z;
    scanf("%d", &z);

    for (int i = 0; i < z; i++)
    {
        scanf("%d", &n);
        if (m[n] == 0)
        {
            m[n]++;
            mm[s] = n;
            s++;
        }
    }

    for (int i = 0; i < s; i++)
    {
        printf("%d ", mm[i]);
    }
    return 0;
}