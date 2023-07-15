#include<stdio.h>
#include<string.h>
int main()
{
    int n=0,i,len;
    char a[122];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        len=strlen(a);
        if(len<10)
            printf("%s\n",a);
        else
            printf("%c%d%c\n",a[0],strlen(a)-2,a[strlen(a)-1]);
    }
}