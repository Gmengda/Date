#include<stdio.h>

#define OFFSETOF(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

typedef struct std
{
    float a;
    double b;
    int c;
}S;

int main ()
{
    S p;
    
    printf("%d\n",OFFSETOF(S,b));

    return 0;
}