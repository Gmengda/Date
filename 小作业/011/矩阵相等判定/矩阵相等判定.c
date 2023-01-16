#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {

    int mm[10][10];
    int m[10][10];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mm[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] != mm[i][j])
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}