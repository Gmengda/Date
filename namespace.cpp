#include <stdio.h>

using namespace std;

int a = 1;

namespace bit
{
    int a = 2;
}

int main()
{
    int a = 0;
    printf("%d",a);
    // :: 域作用限定域（域作用限定符）
    printf("%d",::a);
    printf("%d",bit::a);
    return 0;
}