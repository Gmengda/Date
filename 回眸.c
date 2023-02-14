#include <stdio.h>

int main()
{
    int a,v1,v2,v;
    scanf("%d%d%d%d",&a,&v1,&v2,&v);
    double t1 = (double)a / (v1 + v2);
    double t2 = (a - t1*v1)/v;
    printf("%lf\n",t1 + t2);
    return 0;
}