#pragma once
#include <stdio.h>
#include <assert.h>

typedef int DListData;

typedef struct DList
{
	DListData m;
	struct DList* next;
	struct DList* prve;
}DL;

//初始化头节点
DL* InitDList();

//双向链表输出
void DListPrint(DL* m);

//双向链表尾插
void DListendpush(DL* m, DListData x);

//双向链表尾删
void DListendpop(DL* m);

//双向链表头插
void DListheadpush(DL* m, DListData x);

//双向链表头删
void DListheadpop(DL* m);

//双向链表查找


//双向链表插入


//双向链表删除


//双向链表修改


//双向链表销毁
