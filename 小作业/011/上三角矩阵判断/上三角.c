#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Utl(int m[10][10], int n)
{
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (m[i][j] != 0)
            {
                p = 1;
                break;
            }
        }
    }
    if (p == 1)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
}

int main() {
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
    Utl(m, n);

    return 0;
}