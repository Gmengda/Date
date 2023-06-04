#include <iostream>
using namespace std;

int getmonth(int year,int month)
{
    static int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && (year%400 == 0 ||(year % 4 == 0 && year % 100 != 0)))
    {
        return 29;
    }
    return m[month];
}

int main() {
    
    int day = 0;
    int month = 0;
    int year = 0;
     while((scanf("%d",&year))!=EOF)
    {
        scanf("%d",&month);
        scanf("%d",&day);
        for(int i = 0 ; i < month ; i++)
        {
            day += getmonth(year, i);
        }
        printf("%d\n",day);
    }

    return 0;
}
// 64 位输出请用 printf("%lld")