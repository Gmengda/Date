#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int maxProductDifference(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cor);

    return (nums[numsSize - 1]*nums[numsSize - 2] - nums[0]*nums[1]);
}