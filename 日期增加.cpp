#include <iostream>
using namespace std;

static int m[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main() {
    int i = 0;
    int n;
    int year, month, day, add;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&year);
        scanf("%d",&month);
        scanf("%d",&day);
        scanf("%d",&add);
        day += add;
        while(day > m[i][month])
        {
            if(month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
            {
                i = 1;
            }
            day -= m[i][month];
            month++;
            if(month == 13)
            {
                month = 1;
                year++;

            }
            i = 0;
        }
        if(month < 10)
        {

                printf("%d-0%d-", year, month);

        }
        else 
        {
            printf("%d-%d-", year, month);
        }
        if(day < 10)
        {
            printf("0%d\n", day);
        }
        else
        {
            printf("%d\n", day);
        }
    }
}
// 64 位输出请用 printf("%lld")