#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define defaul_sz 3
#define defaul_move 2

typedef struct peo
{
	char name[10];
	char sex[5];
	int age;
	char addr[20];
	char phone[20];
}P;

typedef struct contacts
{
	P* p;
	int sz;
	int move;
}tact;

//初始化通讯录
void initcontact(tact* p);

//检查有没有空间
void checktact(tact* p);

//添加新成员
void Addcontact(tact* p);

//删除成员
void Delcontact(tact* p);

//查找成员
void searchcontact(const tact* p);

//修改成员
void Moidfycontact(tact* p);

//展示成员
void Showcontact(const tact* p);

//按名字排序
void Sortcontact(tact* p);