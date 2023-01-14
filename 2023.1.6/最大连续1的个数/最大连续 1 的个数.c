#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int m = 0;
    int z = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            z++;
        }
        else
        {
            if (z > m)
            {
                m = z;
            }
            z = 0;
        }
        if (z > m)
        {
            m = z;
        }
    }
    return m;
}