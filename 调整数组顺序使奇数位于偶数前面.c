#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int* exchange(int* nums, int numsSize, int* returnSize){
    int L = 0;
    int R = numsSize - 1;
    while(L < R)
    {
        while(nums[L] % 2 == 1 && L < R)
        {
            L++;
        }
        while(nums[R] % 2 == 0 && L < R)
        {
            R--;
        }
        int m = nums[L];
        nums[L] = nums[R];
        nums[R] = m;
        L++;
        R--;
    }
    *returnSize = numsSize;
    return nums;
}