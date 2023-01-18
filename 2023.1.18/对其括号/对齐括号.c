#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char check(char m)
{
    if (m == ')')
    {
        return '(';
    }
    else if (m == '}')
    {
        return '{';
    }
    else
    {
        return '[';
    }
}
bool isValid(char* s) {
    char m[5000] = { 0 };
    int a = 0;
    int b = 0;
    int n = strlen(s);
    if (n % 2 != 0)
    {
        return false;
    }
    while (*s)
    {
        if (*s == '(' || *s == '{' || *s == '[')
        {
            m[a] = *s;
            a++;
        }
        else
        {
            if (a == 0)
            {
                b++;
                if (b = 2)
                {
                    return false;
                }
                s++;
                break;
            }
            b = 0;
            if (check(*s) == m[a - 1])
            {
                a--;
            }
            else
            {
                return false;
            }
        }
        s++;
    }
    if (a == 0 && m[a] != '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    char m[100] = {0};
    scanf("%[^\n]", &m);
    printf("%d", isValid(m));
    return 0;
}