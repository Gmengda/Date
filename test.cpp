#define _CRT_SECURE_NO_WARNINGS 1
#include "DictionaryException.h"


void menu()
{
    printf("\n*****************欢迎来到电子小词典****************\n"
        "***********1.增加单词          2.删除单词**********\n"
        "***********3.修改单词          4.查找单词**********\n"
        "***********5.查看全部单词      6.退出词典**********\n\n");
    printf("请输入您选择的功能：");
}



int main()
{
    TNode* dictionary = NULL;
    FILE* dic = fopen("text.txt","r+");
    InitDictionary(&dictionary, dic);
    int flag = 1;
    do
    {
        TNode* tmp;
        char w[20] = "null";
        char t[20] = "null";
        int index;
        char m[100];
        int OrderFlag = 0;
        menu();
        scanf("%s", m);
        index = atoi(m);

        switch (index)
        {
        case 1:
            
            printf("请输入要插入的单词 ：");
            getchar();
            scanf("%[^\n]", w);
            printf("请输入插入单词的解释：");
            getchar();
            scanf("%[^\n]", t);
            if (TreeFind(dictionary, w) != NULL)
            {
                printf("重复单词，请重新操作。\n");
            }
            else if (strcmp(t, "null") == 0 || strcmp(w, "null") == 0)
            {
                printf("单词记录进入词典格式不正确，请从新操作\n");
            }
            else
            {
                InsertWord(&dictionary, w, t, dic);
                printf("增加成功！\n");
            }
            break;
        case 2:
            if (dictionary == NULL)
            {
                printf("词典中没有单词，请添加单词。\n");
                break;
            }
            printf("请输入需要删除的单词");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                DelTxtWord(&dictionary, w);
                DelWord(&dictionary, w);
                printf("删除成功！");
            }
            else
            {
                printf("词典中没有单词:%s，请重新操作，\n",w);
            }
            break;
        case 3:
            printf("请输入需要修改的单词");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                printf("请输入修改后的释义");
                getchar();
                scanf("%[^\n]", t);
                strcpy(tmp->translation, t);
            }
            else
            {
                printf("词典中没有该单词，请重新操作，\n");
            }
            break;
        case 4:
            printf("请输入需要查找的单词");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                printf("\n%s 的解释是 %s\n", tmp->word, tmp->translation);
            }
            else
            {
                printf("词典中没有该单词，请重新操作，\n");
            }
            break;
        case 5:
            do
            {
                printf("可查看单词的选择有：   1.前序遍历  2.中序遍历  3.后序遍历\n");
                printf("请选择：");
                int Order;
                scanf("%d", &Order);
                switch (Order)
                {
                case 1:
                    PreOrder(dictionary, dic);
                    OrderFlag = 0;
                    break;
                case 2:
                    InOrder(dictionary, dic);
                    OrderFlag = 0;
                    break;
                case 3:
                    PostOrder(dictionary, dic);
                    OrderFlag = 0;
                    break;
                default:
                    printf("输入错误，请重新输入！\n");
                    OrderFlag = 1;
                    break;
                }
            } while (OrderFlag);
            break;
        case 6:
            flag = 0;
            printf("退出成功！欢迎下次使用\n");
            break;
        default:
            printf("输入错误，请重新输入！\n");
        }

    } while (flag);
    Desert(&dictionary);

    fclose(dic);
    return 0;
}