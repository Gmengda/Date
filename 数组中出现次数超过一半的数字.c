#include<stdio.h>

int cor(const void* a,const void* b)
{
    return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize){
    int temp = 0,count = 0;
    for(int i=0; i<numsSize; i++)
    {
        if(count == 0)
        {
            temp = nums[i];
            count++;
        }
        else if(temp == nums[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return temp;
}