#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int n = strlen(s);
    int m = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            m++;
        }
        else if (m == 0 && s[i] == ' ')
        {

        }
        else if (s[i] == ' ')
        {
            break;
        }
    }
    return m;

}

int main()
{
    char s[50] = "hellow world";

    printf("%d", lengthOfLastWord(s));

    return 0;
}