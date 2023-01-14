#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//	int* a = (int*)malloc(sizeof(int) * 100000);
//	int sum = 1;
//	int flag = 0;
//
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == 0)
//		{
//			flag++;
//			continue;
//		}
//		sum *= nums[i];
//	}
//	if (flag > 1)
//	{
//		for (int i = 0; i < numsSize; i++)
//		{
//
//			a[i] = 0;
//		}
//	}
//	else if (flag == 1)
//	{
//		for (int i = 0; i < numsSize; i++)
//		{
//			if (nums[i] == 0)
//			{
//				a[i] = sum;
//			}
//			else
//			{
//				a[i] = 0;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < numsSize; i++)
//		{
//			if ((sum < 0 && nums[i]>0) || (nums[i] < 0 && sum>0))
//			{
//				for (flag = -1;; flag--)
//				{
//					if (flag * nums[i] == sum)
//					{
//						a[i] = flag;
//						break;
//					}
//				}
//			}
//			else
//			{
//				for (flag = 1;; flag++)
//				{
//					if (flag * nums[i] == sum)
//					{
//						a[i] = flag;
//						break;
//					}
//				}
//			}
//		}
//	}
//	*returnSize = numsSize;
//	return a;
//}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* left = (int*)malloc(sizeof(int) * numsSize);
    int* right = (int*)malloc(sizeof(int) * numsSize);
    left[0] = 1;
    right[numsSize - 1] = 1;
    for (int i = 1; i < numsSize; i++)
    {
        left[i] = nums[i - 1] * left[i - 1];
    }
    for (int i = numsSize - 2; i >= 0; i--)
    {
        right[i] = nums[i + 1] * right[i + 1];
    }
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = left[i] * right[i];
    }
    *returnSize = numsSize;
    return nums;
}

int main()
{
	int z[10000] = { 0 };
	int n = 0;
	int m = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &z[i]);

	int* arr = productExceptSelf(z, n, &m);

	for (int i = 0; i < m; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}