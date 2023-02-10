#define _CRT_SECURE_NO_WARNINGS 1
#include "text.h"

//静态
//void initcontact(tact* p)
//{
//	assert(p);
//	p->sz = 0;
//	memset(p->p, 0, sizeof(p->p));
//}

void initcontact(tact* p)
{
	assert(p);
	p->sz = 0;
	P* ptr = (P*)calloc(defaul_sz, sizeof(P));
	if (ptr == NULL)
	{
		perror("initcontact::calloc");
		return;
	}
	p->p = ptr;
	p->move = defaul_sz;
}

void checktact(tact* p)
{
	assert(p);
	if (p->sz == p->move)
	{
		P* ptr = (P*)realloc(p->p, (p->move + defaul_move) * sizeof(P));
		if (ptr == NULL)
		{
			perror("checktact::realloc");
			return;
		}
		p->p = ptr;
		p->move += defaul_move;
		printf("增容成功！\n");
	}
}

//静态
//void Addcontact(tact* p)
//{
//	assert(p);
//	if (p->sz == 100)
//	{
//		printf("抱歉！通讯录已满。");
//		return;
//	}
//	printf("请输入姓名：");
//	scanf("%s", p->p[p->sz].name);
//	printf("请输入性别：");
//	scanf("%s", p->p[p->sz].sex);
//	printf("请输入年龄：");
//	scanf("%d", &p->p[p->sz].age);
//	printf("请输入地址：");
//	scanf("%s", p->p[p->sz].addr);
//	printf("请输入电话：");
//	scanf("%s", p->p[p->sz].phone);
//	p->sz++;
//}

void Addcontact(tact* p)
{
	assert(p);
	checktact(p);

	printf("请输入姓名：");
	scanf("%s", p->p[p->sz].name);
	printf("请输入性别：");
	scanf("%s", p->p[p->sz].sex);
	printf("请输入年龄：");
	scanf("%d", &p->p[p->sz].age);
	printf("请输入地址：");
	scanf("%s", p->p[p->sz].addr);
	printf("请输入电话：");
	scanf("%s", p->p[p->sz].phone);
	p->sz++;
}

void Delcontact(tact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录中没有成员！\n");
		return;
	}
	char name[10];
	printf("请输入需要删除的姓名：");
	scanf("%s", name);
	for (int i = 0; i < p->sz; i++)
	{
		if (strcmp(name, p->p[i].name) == 0)
		{
			for (int j = i; j < p->sz - 1; j++)
			{
				p->p[j] = p->p[j + 1];
			}
			p->sz--;
			return;
		}
		else if (i == p->sz - 1)
		{
			printf("没有该成员！");
		}
	}
}

void searchcontact(const tact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录中没有成员！\n");
		return;
	}
	char name[10];
	printf("请输入需要查找的姓名：");
	scanf("%s", name);
	for (int i = 0; i < p->sz; i++)
	{
		if (strcmp(p->p[i].name, name) == 0)
		{
			printf("%-20s%-4s%-5s%-20s%-12s\n", "名字", "性别", "年龄", "地址", "电话");
			printf("%-20s%-4s%-5d%-20s%-12s\n"
										, p->p[i].name
										, p->p[i].sex
										, p->p[i].age
										, p->p[i].addr
										, p->p[i].phone);
			return;
		}
		else if (i == p->sz - 1)
		{
			printf("没有该成员信息！");
		}
	}
}

void Moidfycontact(tact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录中没有成员！\n");
		return;
	}
	char name[10];
	printf("请输入需要修改的姓名：");
	scanf("%s", name);
	for (int i = 0; i < p->sz; i++)
	{
		if (strcmp(p->p[i].name, name) == 0)
		{
			printf("请输入姓名：");
			scanf("%s", p->p[i].name);
			printf("请输入性别：");
			scanf("%s", p->p[i].sex);
			printf("请输入年龄：");
			scanf("%d", &p->p[i].age);
			printf("请输入地址：");
			scanf("%s", p->p[i].addr);
			printf("请输入电话：");
			scanf("%s", p->p[i].phone);
			return;
		}
		else if (i == p->sz - 1)
		{
			printf("没有该成员信息！");
		}
	}
}

void Showcontact(const tact* p)
{
	assert(p);
	if (p->sz == 0)
	{
		printf("通讯录中没有成员！\n");
		return;
	}
	printf("%-20s%-4s%-5s%-20s%-12s\n", "名字", "性别", "年龄", "地址", "电话");
	for (int i = 0; i < p->sz; i++)
	{
		printf("%-20s%-4s%-5d%-20s%-12s\n"
									, p->p[i].name
									, p->p[i].sex
									, p->p[i].age
									, p->p[i].addr
									, p->p[i].phone);
	}
}

int cor(const void* a, const void* b)
{
	return strcmp(((P*)a)->name, ((P*)b)->name);
}

void Sortcontact(tact* p)
{
	qsort(p->p[0].name, p->sz, sizeof(p->p[0]), cor);
	printf("排序成功！\n");
}