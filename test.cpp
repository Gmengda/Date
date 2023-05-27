#define _CRT_SECURE_NO_WARNINGS 1
#include "DictionaryException.h"


void menu()
{
    printf("\n*****************��ӭ��������С�ʵ�****************\n"
        "***********1.���ӵ���          2.ɾ������**********\n"
        "***********3.�޸ĵ���          4.���ҵ���**********\n"
        "***********5.�鿴ȫ������      6.�˳��ʵ�**********\n\n");
    printf("��������ѡ��Ĺ��ܣ�");
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
            
            printf("������Ҫ����ĵ��� ��");
            getchar();
            scanf("%[^\n]", w);
            printf("��������뵥�ʵĽ��ͣ�");
            getchar();
            scanf("%[^\n]", t);
            if (TreeFind(dictionary, w) != NULL)
            {
                printf("�ظ����ʣ������²�����\n");
            }
            else if (strcmp(t, "null") == 0 || strcmp(w, "null") == 0)
            {
                printf("���ʼ�¼����ʵ��ʽ����ȷ������²���\n");
            }
            else
            {
                InsertWord(&dictionary, w, t, dic);
                printf("���ӳɹ���\n");
            }
            break;
        case 2:
            if (dictionary == NULL)
            {
                printf("�ʵ���û�е��ʣ�����ӵ��ʡ�\n");
                break;
            }
            printf("��������Ҫɾ���ĵ���");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                DelTxtWord(&dictionary, w);
                DelWord(&dictionary, w);
                printf("ɾ���ɹ���");
            }
            else
            {
                printf("�ʵ���û�е���:%s�������²�����\n",w);
            }
            break;
        case 3:
            printf("��������Ҫ�޸ĵĵ���");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                printf("�������޸ĺ������");
                getchar();
                scanf("%[^\n]", t);
                strcpy(tmp->translation, t);
            }
            else
            {
                printf("�ʵ���û�иõ��ʣ������²�����\n");
            }
            break;
        case 4:
            printf("��������Ҫ���ҵĵ���");
            getchar();
            scanf("%[^\n]", w);
            tmp = TreeFind(dictionary, w);
            if (tmp != NULL)
            {
                printf("\n%s �Ľ����� %s\n", tmp->word, tmp->translation);
            }
            else
            {
                printf("�ʵ���û�иõ��ʣ������²�����\n");
            }
            break;
        case 5:
            do
            {
                printf("�ɲ鿴���ʵ�ѡ���У�   1.ǰ�����  2.�������  3.�������\n");
                printf("��ѡ��");
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
                    printf("����������������룡\n");
                    OrderFlag = 1;
                    break;
                }
            } while (OrderFlag);
            break;
        case 6:
            flag = 0;
            printf("�˳��ɹ�����ӭ�´�ʹ��\n");
            break;
        default:
            printf("����������������룡\n");
        }

    } while (flag);
    Desert(&dictionary);

    fclose(dic);
    return 0;
}