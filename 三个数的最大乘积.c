#include <stdio.h>
#include <stdlib.h>

int cor(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int maximumProduct(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cor);
    int a = (nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3]);
    if(nums[0] < 0)
    {
        int m = 1;
        int left = 0;
        int right = numsSize - 1;
        for(int i = 0 ; i < 3 ; i++)
        {
            if(-nums[left] >= nums[right] && left != 2)
            {
                m *= nums[left++];
            }
            else
            {
                m *= nums[right--];
            }
        }
        if(m < 0)
        {
            return (a > nums[0]*nums[1]*nums[numsSize - 1] ? a : nums[0]*nums[1]*nums[numsSize - 1]);
        }
        else
        {
            return m;
        }
    }
    else
    {
        return a;
    }
}
int main()
{
    int m[] = {1,2,3};
    int n[] = {2};
    findRadius(m,3,n,1);

    return 0;
}