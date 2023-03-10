#include <stdio.h>
#include <stdlib.h>

int cor(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) 
    {
        while (left < right && nums[left] % 2 == 0) 
        {
            left++;
        }
        while (left < right && nums[right] % 2 == 1) 
        {
            right--;
        }
        if (left < right) 
        {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    *returnSize = numsSize;
    return nums;
}