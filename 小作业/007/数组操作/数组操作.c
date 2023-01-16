#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void init(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//·ÇµÝ¹é
void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	
	while (left < right)
	{
		int m = arr[left];
		arr[left] = arr[right];
		arr[right] = m;
		left++;
		right--;
	}
}

int main()
{
	int m[] = {1,2,3,4,5,6};
	int arr[8];
	int sz = sizeof(arr) / sizeof(arr[0]);
	int sm = sizeof(m) / sizeof(m[0]);

	init(arr, sz);
	print(arr, sz);
	print(m, sm);
	reverse(m,sm);
	print(m, sm);

	return 0;
}

