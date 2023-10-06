#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#define MaxSize 50
#define Increment 10
#define ElemType int
typedef int BOOL;
#define True 1
#define False 0
//定义结构体
typedef struct{
    ElemType * elem;
    int length;
    int listsize;
}SqList,* PSqList;

BOOL ListEmpty(SqList L)
{
    if(L.length==0)
        return True;
    return False;
}
void DestroyList(SqList * L)
{
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
}
//动态数组实现初始化顺序表
SqList InitList()
{
    SqList L;
    L.elem=(ElemType *)malloc(MaxSize*sizeof(ElemType));
    if(!L.elem)
        exit(-1);
    L.length=0;
    L.listsize=MaxSize;
    return L;
}
//使用动态数组实现创建顺序表操作
SqList CreateList(int n)
{
    int i,len;
    SqList L;
    L=InitList();
    printf("请输入顺序表：\n");
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个元素：\n",i+1);
        scanf("%d",&L.elem[i]);
    }
    L.length=n;
    return L;
}
//打印顺序表
void PrintList(SqList L)
{
    int i;
    if(L.length==0)
    {
        printf("空表！\n");
        return;
    }
    printf("顺序表为：\n");
    for(i=0;i<L.length;i++)
    {
        printf("%d\t",L.elem[i]);
    }
    printf("\n");
}
//顺序表插入操作
BOOL InsertList(SqList * L,int i,ElemType e)
{
    ElemType *newbase,*p,*q;
    int j;
    if(i<1 || i>L->length+1)
    {
        printf("插入位置不合理。\n");
        return False;
    }
    if(L->length>=L->listsize)
    {
        newbase=(ElemType *)realloc(L->elem,(L->listsize+Increment)*sizeof(ElemType));
        if(!newbase) exit(-1);
        L->elem=newbase;
        L->listsize+=Increment;
    }
    for(j=L->length;j>=i-1;j--)
    {
        L->elem[j+1]=L->elem[j];
    }
    L->elem[i-1]=e;
    L->length++;
    return True;
}
//顺序表的删除
BOOL ListDelete(SqList *L,int i,ElemType *e)
{
    int j;
    if(i<1||i>L->length)
    {
        printf("删除位置不合理！\n");
        return False;
    }
    *e=L->elem[i-1];
    for(j=i;j<=L->length-1;j++)
    {
        L->elem[j-1]=L->elem[j];
    }
    L->length--;
    return True;
}
//顺序表定位元素
int LocateElem(SqList L,ElemType e)
{
    int i;
    for(i=0;i<=L.length-1;i++)
    {
        if(L.elem[i]==e)
        return i+1;
    }
    return 0;
}
//顺序表读取操作
BOOL GetElem(SqList L,int i,ElemType *e)
{
    if(i<1||i>L.length)
    {
        printf("查找位置错误，无法查询到结果!\n");
        return False;
    }
    *e=L.elem[i-1];
    return True;
}
//顺序表表长
int ListLength(SqList L)
{
    return L.length;
}
//合并顺序表
BOOL Combine(SqList La,SqList Lb,SqList *Lc)
{	
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pa=La.elem;
    pb=Lb.elem;
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;//指向最后一个元素
	Lc->listsize=Lc->length=La.length+Lb.length;
	pc=Lc->elem=(ElemType *)malloc(sizeof(ElemType)*Lc->listsize);
    if(!Lc->elem) exit(-1);
	while(pa<=pa_last &&pb<=pb_last)
	{ 
        if(*pa<*pb)
            *pc++ =*pa++;
	    else
	        *pc++ =*pb++;
	}
	while(pa<=pa_last)
    {
        *pc++ =*pa++;
    }
	while(pb<=pb_last)
    {
		*pc++ =*pb++;
    }
}

void main()
{
	SqList L,La,Lb,Lc;
	int i=0,choice=0,n;
	ElemType e=0;
    do{
	    printf("**************顺序表操作**************\n");
	    printf("**************1-----建表**************\n");
	    printf("**************2-----判空**************\n");
	    printf("**************3-----求表长************\n");
	    printf("**************4-----查询**************\n");
	    printf("**************5-----插入**************\n");
	    printf("**************6-----删除**************\n");
	    printf("**************7-----定位**************\n");
	    printf("**************8-----合并**************\n");
	    printf("**************0-----退出**************\n");
	    printf("请输入想要进行的操作(0-8)：\n");
	    scanf("%d",&choice);
	    switch(choice)
	    {
	        case 1: 
                printf("请输入元素个数：\n");
                scanf("%d",&n);
                if(n>0)
                {
                    L=CreateList(n);
                    PrintList(L);
                }
                else
                    printf("输入数值不正确！\n");
                break;
	        case 2: 
		        if(ListEmpty(L))
			        printf("空表！\n");
		        else
			        printf("顺性表不空！\n");
		        break;
	        case 3: 
		        printf("顺序表长度为%d\n",ListLength(L));
			    break;
	        case 4: 
		        printf("请输入要查询元素的位置：\n");
		        scanf(" %d",&i);
		        if(GetElem(L,i,&e))
		        { 
                    printf("%d位置元素为%d\n",i,e);		  
		        }
		        break;
	        case 5:
		        printf("要输入的数据为：\n");
		        scanf(" %d",&e);
		        printf("要输入的位置为：\n");
		        scanf(" %d",&i);
		        if(InsertList(&L,i,e))
		        { 
                    printf("插入成功！\n");
		            PrintList(L);
                }
		        break;
	        case 6:
		        printf("要删除的位置为：\n");
		        scanf(" %d",&i);
		        if(ListDelete(&L,i,&e))
		        { 
                    printf("第%d个元素%d删除成功！\n",i,e);
		            PrintList(L);
		        }
		        break;
            case 7:
                printf("要查询的元素为：\n");
                scanf("%d",&e);
                if(LocateElem(L,e))
                    printf("%d的位置为%d\n",e,LocateElem(L,e));
                else
                    printf("元素%d不在顺序表中！\n",e);
                break;
	        case 8:
		        printf("请构造两个顺序表，元素为非递减序列！\n");
		        printf("请构造La，元素为非递减序列！\n");
                printf("请输入La的元素个数（大于零的整数）：");
                scanf("%d",&n);
	            La=CreateList(n); 
                if(La.length)
                    PrintList(La);
	            printf("请构造Lb，元素为非递减序列！\n");
                printf("请输入Lb的元素个数（大于零的整数）：");
                scanf("%d",&n);
	            Lb=CreateList(n); 
                if(Lb.length)
                    PrintList(Lb);
	            Combine(La,Lb,&Lc);
	            printf("合并之后:");
	            PrintList(Lc);
	            break;
	   	    case 0:
		        printf("退出！\n");
		        break;
	        default:printf("输入的选项不正确，应为(0-8)，请重试！\n");
		        break;
	    }
    }
    while(choice);
    system("pause");
}