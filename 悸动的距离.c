#include <stdio.h>
 
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int m = 2;
    if(( a > 0 && c > 0) || ( a < 0 && c < 0) || a == 0 || c == 0)
    {
        m--;
    }
    if(( b > 0 && d > 0) || ( b < 0 && d < 0) || b == 0 || d == 0)
    {
        m--;
    }
	if((float)b / a == (float)d / c && m != 0)
	{
		m++;
	}
	if((a == 0 && b == 0) || (c == 0 && d == 0))
	{
		m = 1;
	})
    printf("%d",m);
    return 0;
}