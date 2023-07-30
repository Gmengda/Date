#include<stdio.h>

int main()
{
    int result[150]={0,1,2};
    for(int i=3;i<150;++i)
    {
        result[i]=(2*result[i-1]+result[i-2])%32767;
    }
    int k;
    scanf("%d",&k);
    while(k--) {
        int num;
        scanf("%d", &num);
        printf("%d\n", result[num%150]);
    }
    return 0;
}