#include <stdio.h>
#include <stdlib.h>

int cor(const void*a,const void* b)
{
    return *(int*)a > *(int*)b;
}

int thirdMax(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cor);
    int m[10000] = {0};
    int p = 0;
    for(int i = 0 ; i < numsSize ; i++)
    {
        m[p]++;
        if(i != numsSize - 1 && nums[i] != nums[i + 1])
        {
            p++;
        }
    }
    if(p == 0)
    {
        return nums[0];
    }
    else if(p == 1)
    {
        return nums[numsSize - 1];
    }
    else
    {
        return nums[numsSize - m[p] - m[p - 1] - 1];
    }
}