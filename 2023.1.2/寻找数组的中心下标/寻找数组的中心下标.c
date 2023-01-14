#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int pivotIndex(int* nums, int numsSize) {
//	int* a = nums;
//	int left = 0;
//	int right = 0;
//	int m = 0;
//
//	for (int i = 0; i < numsSize; i++,m++)
//	{
//		left = 0;
//		right = 0;
//		a = nums;
//		for (int j = 0; j < numsSize; j++)
//		{
//			if (j < i)
//			{
//				left += *a;
//			}
//			else if (j > i)
//			{
//				right += *a;
//			}
//			a++;
//		}
//		if (left == right)
//		{
//			return i;
//		}
//		else if (m == numsSize - 1)
//		{
//			return -1;
//		}
//	}
//}

int pivotIndex(int* nums, int numsSize) {
	int sum = 0;
	int m = 0;

	for (int i = 0; i < numsSize; i++)
	{
		sum += nums[i];
	}

	for (int i = 0; i < numsSize; i++)
	{
		if (2 * m + nums[i] == sum)
		{
			return i;
		}
		m += nums[i];
	}
	return -1;
	
}

int main()
{
	int a[1000] = { 0 };
	int n;

	scanf("%d", &n);
	for(int i = 0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("%d", pivotIndex(a, n));

	return 0;
}