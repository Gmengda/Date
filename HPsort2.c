#define _CRT_SECURE_NO_WARNINGS 1
#include "HPsort.h"

//交换
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

//建堆
void createHP(int* m, int node)
{
	/*for (int i = 0; i < node; i++)
	{
		push(m, i);
	}*/


	for (int i = (node - 1) / 2; i >= 0 ; i--)
	{
		down(m, node,i);
	}
}


//向上调整
void push(int* m, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (m[child] > m[parent])
		{
			swap(&m[child], &m[parent]);
		}
		else
		{
			break;
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//向下调整
void down(int* m, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && m[child + 1] < m[child])
		{
			child++;
		}
		if (m[parent] > m[child])
		{
			swap(&m[parent], &m[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


//取前k项最大数
int* Topn(int* m, int size, int k)
{
	assert(m);

	//初始化数组
	int* arr = (int*)malloc(sizeof(int) * (k + 1));
	if (arr == NULL)
	{
		perror("Yopn malloc");
		return NULL;
	}
	for (int i = 0; i < k; i++)
	{
		arr[i] = m[i];
	}

	//建堆
	createHP(arr, k);


	//逐一相比
	for (int i = k; i < size; i++)
	{
		if (m[i] > arr[0])
		{
			arr[0] = m[i];
			down(arr, k, 0);
		}
	}

	return arr;
}
