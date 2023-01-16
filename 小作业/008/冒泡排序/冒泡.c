#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void swap(int* a, int* b)
{
	int m = *a;
	*a = *b;
	*b = m;
}

void max(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(&arr[i], &arr[i + 1]);
		}
	}
}

//·ÇµÝ¹é
void opop(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

//°ëµÝ¹é
void OpOp(int arr[], int sz)
{
	if (sz > 1)
	{
		max(arr, sz);
		OpOp(arr, sz - 1);
	}
}


int main() 
{
	int arr[] = { 3,4,5,6,8,2,1,7,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	opop(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}