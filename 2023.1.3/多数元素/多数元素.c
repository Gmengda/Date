#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int majorityElement(int* nums, int numsSize) {
//    int m = 0;
//
//    for (int i = 0; i < numsSize; i++)
//    {
//        m = 0;
//        for (int j = 0; j < numsSize; j++)
//        {
//            if (nums[i] == nums[j])
//            {
//                m++;
//            }
//        }
//        if (m > numsSize / 2)
//        {
//            return nums[i];
//        }
//    }
//    return m;
//}
////int majorityElement(int* nums, int numsSize) {
////    int m[25000] = { 0 };
////
////    for (int i = 0; i < numsSize; i++)
////    {
////        m[nums[i]]++;
////        if (m[nums[i]] > numsSize / 2)
////        {
////            return nums[i]];
////        }
////    }
////    return 0;
////}
//int majorityElement(int* nums, int numsSize) {
//    int n, m;
//    m = 1, n = nums[0];
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] != n)
//        {
//            if (m == 0)
//            {
//                n = nums[i], m++;
//            }
//            else
//            {
//                m--;
//            }
//        }
//        else
//        {
//            m++;
//        }
//    }
//    return n;
//}

int majorityElement(int* nums, int numsSize) {
    int n = nums[0];
    int m = 1;
    int s = numsSize;
    while (s)
    {
        for (int i = 1; i < s; i++)
        {
            if (nums[i] == n)
            {
                m++;
            }
            else
            {
                if (m == 0)
                {
                    n = nums[i];
                    m++;
                }
                else
                {
                    m--;
                }
            }
        }
        m = 0;
        for (int i = 0; i < s; i++)
        {
            if (nums[i] == n)
            {
                m++;
            }
        }
        if (m * 2 > numsSize)
        {
            return n;
        }
        s--;
    }
    return -1;
}

int main()
{
	int a[10000] = { 0 };
	int n = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	printf("%d", majorityElement(a, n));

	return 0;
}