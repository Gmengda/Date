#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Print(int arr[], int sz)
{
	int* m = arr;
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", *m);
		m++;
	}
}

int main()
{

	int arr[] = { 1,2,3,4,5,6,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	Print(arr, sz);

	return 0;
}