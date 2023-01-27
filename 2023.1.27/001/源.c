#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

enum Color//ÑÕÉ«
{
    RED = 1,
    GREEN = 2,
    BLUE = 4
};

int main()
{
    enum Color clr = GREEN;
    clr = 5;
    printf("%d", clr);
    printf("%d", RED);
    printf("%d", GREEN);
    printf("%d", BLUE);
    
    int* p;
    p = 0;
    p = NULL;
    
    return 0;

}