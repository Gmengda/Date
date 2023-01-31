#include<stdio.h>
struct Tday
{
    int year;
    int mouth;
    int day;
};
int main()
{
    struct Tday a1={0};
        scanf("%d",&(a1.year));
        scanf("%d",&(a1.mouth));
        scanf("%d",&(a1.day));
    printf("%d/%d/%d",a1.day,a1.mouth,a1.year);
    return 0;
}