#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    char m[1000];
    int n = 0;
    scanf("%s", m);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%c", m[i]);
    }
    return 0;
}