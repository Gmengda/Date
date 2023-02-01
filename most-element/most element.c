// int sort(const void* a,const void* b)
// {
//     return *(int*)a - *(int*)b;
// }

// int majorityElement(int* nums, int numsSize){
//     qsort(nums,numsSize,sizeof(nums[0]),sort);
//     return nums[numsSize/2];
// }
#include <stdio.h>
int majorityElement(int *nums, int numsSize)
{
    int m = 1;
    int z = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (z == nums[i])
        {
            m++;
        }
        else
        {
            m--;
            if (m == 0)
            {
                z = nums[i];
                m = 1;
            }
        }
    }
    return z;
}

int main()
{
    int m;
    int arr[3] = {3, 3, 3};
    scanf("%d",&m);
    printf("%d", majorityElement(arr, 3));
    return 0;
}