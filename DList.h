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

//��ʼ��ͷ�ڵ�
DL* InitDList();

//˫���������
void DListPrint(DL* m);

//˫������β��
void DListendpush(DL* m, DListData x);

//˫������βɾ
void DListendpop(DL* m);

//˫������ͷ��
void DListheadpush(DL* m, DListData x);

//˫������ͷɾ
void DListheadpop(DL* m);

//˫���������


//˫���������


//˫������ɾ��


//˫�������޸�


//˫����������
