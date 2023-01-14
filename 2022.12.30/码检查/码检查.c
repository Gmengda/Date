#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char arr[100] = { 0 };

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        getchar();
        int a = 0, b = 0, c = 0;

        scanf("%[^\n]", arr);
        int m = strlen(arr);

        if ((m < 8) || (arr[0] >= '0' && arr[0] <= '9'))
        {
            printf("NO\n");
            continue;
        }

        for (int j = 0; j < m; j++)
        {
            if ((arr[j] < '0' || arr[j] > 'z') || (arr[j] > '9' && arr[j] < 'A') || (arr[j] > 'Z' && arr[j] < 'a'))
            {
                printf("NO\n");
                break;
            }
            if (arr[j] >= '0' && arr[j] <= '9')
            {
                a++;
            }
            else if (arr[j] >= 'a' && arr[j] <= 'z')
            {
                b++;
            }
            else
            {
                c++;
            }
        }
        if (a == m || b == m || c == m)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
    }

    return 0;
}