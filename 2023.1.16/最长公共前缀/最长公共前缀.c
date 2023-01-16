#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

//Á¦¿Û
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 1) { return *strs; }
    if (strsSize == 0) { return ""; }
    char* m = (char*)malloc(200);
    memset(m, '\0', sizeof(200 * sizeof(char)));
    int n = 0;
    int flag = 1;
    for (int i = 0; i < strsSize; i++)
    {
        if (strlen(strs[i]) == 0)
        {
            return  "";
        }
    }
    while (flag)
    {
        for (int i = 0; i < strsSize - 1; i++)
        {
            if (strs[i][0] == '\0' || strs[i + 1][0] == '\0' || strs[i][0] != strs[i + 1][0])
            {
                flag = 0;
                m[n] = '\0';
                break;
            }
        }
        if (flag)
        {
            m[n] = strs[0][0];
            n++;
            for (int i = 0; i < strsSize; i++)
            {
                strs[i]++;
            }
        }
    }
    return  m;
}

//Å£¿Í
char* longestCommonPrefix(char** strs, int strsLen) {
    if (strsLen == 1) { return *strs; }
    if (strsLen == 0) { return ""; }
    char* m = (char*)malloc(5000);
    memset(m, '\0', sizeof(200 * sizeof(char)));
    int n = 0;
    int flag = 1;
    for (int i = 0; i < strsLen; i++)
    {
        if (strlen(strs[i]) == 0)
        {
            return  "";
        }
    }
    while (flag)
    {
        for (int i = 0; i < strsLen - 1; i++)
        {
            if (strs[i][0] == '\0' || strs[i + 1][0] == '\0' || strs[i][0] != strs[i + 1][0])
            {
                flag = 0;
                m[n] = '\0';
                break;
            }
        }
        if (flag)
        {
            m[n] = strs[n][0];
            n++;
            for (int i = 0; i < strsLen; i++)
            {
                strs[i]++;
            }
        }
    }
    return  m;
}

int main()
{
	int n = 0;
	char a[10] = "flower";
	char b[10] = "flower";
	char c[10] = "flower";
    char d[10] = "flower";
	char* arr[10] = { a,b,c,d };

	char* m = longestCommonPrefix(arr, 4);

	printf("%s", m);

	return 0;
}