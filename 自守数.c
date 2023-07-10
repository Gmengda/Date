#include<stdio.h>
int main()
{
    unsigned long getNum =0 ;
    while(scanf("%d",&getNum)!=EOF)
    {
        unsigned long sum;
        int no=0;
        int i=0;
        getchar();
        for(i=0;i<=getNum;i++)
        {
            sum=i*i;
            if(sum%10 == i   ||
               sum%100 == i  ||
               sum%1000 == i ||
               sum%10000 == i||
               sum%100000 == i)
            {
                no++;
            }
        }
        printf("%d\n",no);
    }
    return 0;
}