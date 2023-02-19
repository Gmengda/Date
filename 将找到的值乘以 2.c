#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int findFinalValue(int* nums, int numsSize, int original){
    qsort(nums,numsSize,sizeof(int),cor);

    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == original)
        {
            original *= 2;
        }
    }
    return original;
}