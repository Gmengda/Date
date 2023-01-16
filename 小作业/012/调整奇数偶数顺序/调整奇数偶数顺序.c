#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void SORT(int* arr, const int sz)
//{
//	for (int i = 0; i < (sz / 2); i++)
//	{
//		for (int j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] % 2 == 0)
//			{
//				int m = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = m;
//			}
//		}
//	}
//}

int* SORT(int* arr, const int sz)
{
	int* left = arr;
	int* right = arr + sz - 1;
	while (left < right)
	{
		if (*right % 2 == 1)
		{
			for (; left < right;)
			{
				if (*left % 2 == 0)
				{
					int m = *left;
					*left = *right;
					*right = m;
					break;
				}
				else
				{
					left++;
				}
			}
		}
		right--;
	}
	return arr;
}

int main()
{
	int arr[] = { 1,1,4,4,4,5,8,6,9,7,1,43,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);

	SORT(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}