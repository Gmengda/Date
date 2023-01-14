#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int m[10000] = { 0 };
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    *returnSize = 0;
//    for (int i = 0; i < numsSize; i++)
//    {
//        m[nums[i]]++;
//    }
//    for (int i = 1; i <= numsSize; i++)
//    {
//        if (m[i] == 0)
//        {
//            m[(*returnSize)++] = i;
//        }
//    }
//    return m;
//}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    for (int i = 0; i < numsSize; i++) {
        int x = (nums[i] - 1) % numsSize;
        nums[x] += numsSize;
    }

    int* ret = malloc(sizeof(int) * numsSize);

    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= numsSize) {
            ret[(*returnSize)++] = i + 1;
        }
    }
    return ret;
}

int mian()
{

	return 0;
}