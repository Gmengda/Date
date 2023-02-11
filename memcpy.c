#include <stdio.h>

void *my_memcpy(void *det, const void *src, int num)
{
    char *p1 = (char *)det;
    char *p2 = (char *)src;
    char *ret = p1;

    while (num)
    {
        *p1 = *p2;
        p1++;
        p2++;
    }

    return ret;
    
}