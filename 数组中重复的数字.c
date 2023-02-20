#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int findRepeatNumber(int* nums, int numsSize){
    int m[100000] = {0};
    for(int i = 0 ; i < numsSize ; i++)
    {
        if(m[nums[i]]++ != 0)
        {
            return nums[i];
        }
        
    }
    return 0;
}