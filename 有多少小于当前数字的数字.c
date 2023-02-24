#include<stdio.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int s[102] = {0};
    for(int i = 0 ; i < numsSize ; i++)
    {
        s[nums[i]]++;
    }
    for(int i = 0 ; i < numsSize ; i++)
    {
        int n = 0;
        for(int j = 0 ; j < nums[i] ; j++)
        {
            n += s[j];
        }
        nums[i] = n;
    }
    *returnSize = numsSize;
    return nums;
}