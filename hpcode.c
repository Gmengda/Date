#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"


// �ѵĹ���
void HeapCreate(HP* hp)
{
	assert(hp);

	HPdatatype* tmp = (HPdatatype*)malloc(sizeof(HPdatatype) * 4);
	if (tmp == NULL)
	{
		perror("create malloc fail");
		return;
	}
	hp->m = tmp;
	hp->size = 0;
	hp->capacity = 4;

}


// �ѵ�����
void HeapDestory(HP* hp)
{
	assert(hp);
	free(hp->m);
	hp->m = NULL;
	hp->size = 0;
	hp->capacity = 0;
}

void swap(HPdatatype* a,HPdatatype* b)
{
	HPdatatype c = *a;
	*a = *b;
	*b = c;
}

void push(HP* hp,int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (hp->m[child] > hp->m[parent])
		{
			swap(&hp->m[child], &hp->m[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}


// �ѵĲ���
void HeapPush(HP* hp, HPdatatype* a)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		HPdatatype* tmp = (HPdatatype*)realloc(hp->m,sizeof(HPdatatype) * 2 * hp->capacity);
		if (tmp == NULL)
		{
			perror("create malloc fail");
			return;
		}
		hp->m = tmp;
		hp->capacity *= 2;
	}
	hp->m[hp->size] = a;
	hp->size++;
	push(hp, hp->size - 1);


}

void pop(HP* hp,int size)
{
	int parent = 0;
	int child = 1;
	while (child < size)
	{
		if (child + 1 < size && hp->m[child + 1] > hp->m[child])
		{
			child++;
		}
		swap(&hp->m[parent], &hp->m[child]);
		if (hp->m[child] > hp->m[child * 2 + 1])
		{
			swap(&hp->m[child], &hp->m[child * 2 + 1]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}


}

// �ѵ�ɾ��
void HeapPop(HP* hp)
{
	assert(hp);
	if (hp->size == 0)
	{
		perror("pop size small");
		return;
	}
	else if (hp->size == 1)
	{
		hp->size--;
	}
	else
	{
		swap(&hp->m[0], &hp->m[hp->size - 1]);
		hp->size--;
		pop(hp, hp->size);
	}
}


// ȡ�Ѷ�������
HPdatatype HeapTop(HP* hp)
{
	assert(hp);
	if (!HeapEmpty(hp))
	{
		perror("saturate");
	}
	return hp->m[0];
}


// �ѵ����ݸ���
int HeapSize(HP* hp)
{
	assert(hp);
	return hp->size;

}


// �ѵ��п�
bool HeapEmpty(HP* hp)
{
	assert(hp);
	if (hp->size == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void Heapqsort(HP* hp)
{
	assert(hp);

	for (int i = hp->size; i >= 0; i--)
	{
		pop(hp, i);
	}


}









