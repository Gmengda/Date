#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int dominantIndex(int* nums, int numsSize) {
    int a = 0;
    int n = 0;
    int m = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] >= m)
        {
            n = m;
            m = nums[i];
            a = i;
        }
        else if (nums[i] > n)
        {
            n = nums[i];
        }
    }
    /*if (m >= 2 * n)
    {
        return a;
    }
    else if (m < 2 * n)
    {
        return -1;
    }*/
    return m >= 2 * n ? a : -1;
}

int main()
{
    int a[50];
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", dominantIndex(a, n));

	return 0;
}