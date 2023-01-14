#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int m = 0;
    int n = 0;
    char* z = s;
    while (*z != 0)
    {
        n++;
        z++;
    }
    if (n == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int a[130] = { 0 };
        for (int j = i; j < n + 1; j++)
        {
            if (j == n && m == 0)
            {
                m = j - i;
                break;
            }
            if (a[s[j]] == 1 || a[s[j]] == 0)
            {
                if (m < j - i)
                {
                    m = j - i;
                }
                break;
            }
            
            a[s[j]]++;
        }
    }
    return m;
}

int main()
{

    char s[100];
    scanf("%[^\n]", s);

    printf("%d", lengthOfLongestSubstring(s));

    return 0;
}