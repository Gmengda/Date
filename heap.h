#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPdatatype;

typedef struct Heap
{
	HPdatatype* m;
	int size;
	int capacity;
}HP;


// �ѵĹ���
void HeapCreate(HP* hp);


// �ѵ�����
void HeapDestory(HP* hp);


// �ѵĲ���
void HeapPush(HP* hp, HPdatatype* a);


// �ѵ�ɾ��
void HeapPop(HP* hp);


// ȡ�Ѷ�������
HPdatatype HeapTop(HP* hp);


// �ѵ����ݸ���
int HeapSize(HP* hp);


// �ѵ��п�
bool HeapEmpty(HP* hp);

//����
void Heapqsort(HP* hp);




