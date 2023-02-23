#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}
union Un1
{
char c[5];
int i;
};
union Un2
{
short c[7];
int i;
};
int main()
{
    
//下面输出的结果是什么？
printf("%d\n", sizeof(union Un1));
printf("%d\n", sizeof(union Un2));
    return 0;
}