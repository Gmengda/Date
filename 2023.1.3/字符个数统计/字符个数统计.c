#include <stdio.h>
#include <string.h>

int main() {
    char arr[500];
    int m[127] = { 0 };
    int o = 0;

    scanf("%[^\n]", arr);
    int n = strlen(arr);

    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]] == 0)
        {
            m[arr[i]]++;
            o++;
        }
    }
    printf("%d", o);
    return 0;
}