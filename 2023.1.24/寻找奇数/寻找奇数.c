#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int n;
    int m, a;
    int c = 0;
    scanf("%d", &n);
    scanf("%d", &a);
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &m);
        a ^= m;
    }
    printf("%d", a);
    return 0;
}