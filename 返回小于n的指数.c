# include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int flag = 1;
    int count = 1;
    for(int i=3; i<n; i++)
    {
        for(int j=i-1; j>1; j--)
        {
            if(i%j == 0)
            {
                flag = 0;
                break;
            }
        }
        count += flag;
        flag = 1;
    }
    printf("%d\n", count);
    return 0;
}