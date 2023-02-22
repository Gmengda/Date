#include "SeqList.h"

void mune()
{
    printf("1.ADD\n");
    printf("2.DEL\n");
    printf("3.SERCHED\n");
    printf("4.CHANGE\n");
    printf("5.PRINT\n");
    printf("0.EXIT\n");

}

int main()
{
    int n;
    SL m;

    SL_Init(&m);

    do
    {
        mune();
        printf("请输入需要进行的操作：");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                    break;
            case 1:SL_Add(&m);
                    break;
            case 2:SL_Del(&m);
                    break;
            case 3:SL_searched(&m);
                    break;
            case 4:SL_change(&m);
                    break;
            case 5:SL_print(&m);
                    break;
            default:
            printf("请重新输入！\n");n = 1;
        }
    } while (n);
    
    return 0;
}