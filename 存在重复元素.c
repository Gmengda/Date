#include <string.h>

// int cor(const void* a , const void* b)
// {
//     return *(char*)a - *(char*)b;
// }

// bool isAnagram(char * s, char * t){
//     int a = strlen(s);
//     int b = strlen(t);
//     if(a != b)
//     {
//         return false;
//     }
//     qsort(s,a,sizeof(s[0]),cor);
//     qsort(t,b,sizeof(t[0]),cor);
//     for(int i = 0 ; i < a ; i++)
//     {
//         if(s[i] != t[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }


bool isAnagram(char * s, char * t){
    int a = strlen(s);
    int b = strlen(t);
    int m[26] = {0};
    int n[26] = {0};
    for(int i = 0 ; i < a ; i++)
    {
        m[s[i] - 'a']++;
    }
    for(int i = 0 ; i < b ; i++)
    {
        n[t[i] - 'a']++;
    }
    for(int i = 0 ; i < 26 ; i++)
    {
        if(m[i] != n[i])
        {
            return false;
        }
    }

    return true;
}