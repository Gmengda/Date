#include <stdio.h>

int main(void)
{
    char str[1000];
    int len;
    int i=0;
    int cnt_zifu=0;
    int cnt_shuzi=0;
    int cnt_space=0;
    int cnt_other=0;
    while(gets(str))
    {
    cnt_zifu=0;
    cnt_shuzi=0;
    cnt_space=0;
    cnt_other=0;
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(((str[i]>='A')&&(str[i]<='Z'))||((str[i]>='a')&&(str[i]<='z')))
        {
            cnt_zifu++;
        }
        else if((str[i]>='0')&&(str[i]<='9'))
        {
            cnt_shuzi++;
        }
        else if(str[i]==' ')
        {
            cnt_space++;
        }
        else
        {
            cnt_other++;
        }
    }
    printf("%d\n%d\n%d\n%d\n",cnt_zifu,cnt_space,cnt_shuzi,cnt_other);
    }
    return 0;
}