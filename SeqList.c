#include "SeqList.h"


void SL_Init(SL* m)
{
	assert(m);
	m->size = 0;
	m->capacity = 5;
	m->m = (SLArr*)malloc(sizeof(SLArr) * (m->capacity));
	if(m->m == NULL)
	{
		perror("malloc fail");
		return;
	}
}


void SL_Add(SL* m)
{
	assert(m);
	if(m->size == m->capacity)
	{
		m->m = (SLArr*)realloc(m->m,sizeof(SLArr) * (m->capacity) * 2);
		if(m->m == NULL)
		{
		perror("realloc fail");
		return;
		}
		m->capacity *= 2;
		printf("增容成功\n");
	}
	printf("请输入第%d个元素的内容:",m->size);
	scanf("%d",&m->m[m->size++]);
}


void SL_Del(SL* m)
{
	if(m->size == 0)
	{
		printf("顺序表中没有元素可以删除。\n");
		return;
	}
	m->size--;
	printf("成功删除最后一个元素\n");
}


void SL_searched(SL* m)
{
	assert(m);
	if(m->size == 0)
	{
		printf("顺序表中没有元素可以查询。\n");
		return;
	}
	int n;
	printf("请输入需要查询的编号：");
	scanf("%d",&n);
	printf("查询编号元素的内容是：%d\n",m->m[n]);
}


void SL_change(SL* m)
{
	assert(m);
	if(m->size == 0)
	{
		printf("顺序表中没有元素可以修改。\n");
		return;
	}
	int n;
	printf("请输入需要修改的编号：");
	scanf("%d",&n);
	printf("请输入需要修改的内容：");
	scanf("%d",&m->m[n]);
	printf("修改成功\n");
}


void SL_print(SL* m)
{
	assert(m);
	for(int i = 0; i < m->size; i++)
	{
		printf("%d ",m->m[i]);
	}
	printf("\n");
}



