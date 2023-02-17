#include<stdio.h>

int missingNumber(int* nums, int numsSize){
    int m = 0;
 
 
    for(int i = 0; i < numsSize; i++)
    {
        m += i - nums[i];
    }
    
    return m + numsSize;
}