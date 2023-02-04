#include <stdio.h>
#include <stdlib.h>
int hIndex(int* citations, int citationsSize){
    
    int m[1000] = {0};
    for(int i = 0 ; i < citationsSize ; i++)
    {
        m[citations[i]]++;
    }
    int s = 0;
    for(int i = 999 ; i >= 0 ; i--)
    {
        s += m[i];
        if(s >= i)
        {
            return i;
        }
    }
    return 0;
}