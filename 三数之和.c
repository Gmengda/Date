#include <stdio.h>
#include <stdlib.h>
int sort(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **m = (int**)malloc(sizeof(int*)*18000);
    *returnColumnSizes = (int*)malloc(18000 * sizeof(int));
    int q = 0;
    for(int i = 0 ; i < 18000 ; i++)
    {
        m[i] = (int*)malloc(3 * sizeof(int));
    }
    qsort(nums,numsSize,sizeof(int),sort);

    int a = 0;
    int b = a + 1;
    int c = numsSize - 1;
    
    for( ; a < numsSize - 2 ; a++)
    {
        b = a + 1;
        c = numsSize - 1;
        if(nums[a] > 0)
        {
            *returnSize = q;
            return m;
        }
        else if(nums[c] == 0 && nums[a] == 0 && numsSize != 3)
        {
            c--;
            numsSize--;
        }
        if(a !=0 && nums[a] == nums[a - 1])
        {
            continue;
        }
        while(b < c)
        {
            if(nums[a] + nums[b] + nums[c] > 0)
            {
                c--;
            }
            else if(nums[a] + nums[b] + nums[c] < 0)
            {
                b++;
            }
            else if(nums[a] + nums[b] + nums[c] == 0)
            {
                (*returnColumnSizes)[q] = 3;
                m[q][0] = nums[a];
                m[q][1] = nums[b];
                m[q][2] = nums[c];
                q++;
                while(nums[c] == nums[c - 1] && b < c && numsSize != 3)
                {
                    c--;
                }
                while(nums[b] == nums[b + 1] && b < c && numsSize != 3)
                {
                    b++;
                }
                b++;
                c--;
            }
        }
    }
    *returnSize = q;
    return m;
}

int main()
{
    int num[] = {2,0,-2,-5,-5,-3,2,-4};
    int** m = (int**)malloc(sizeof(int*) * 1000);
    for (int i = 0; i < 1000; i++)
    {
        m[i] = (int*)malloc(sizeof(int) * 3);
    }
    m = zzzz(num,8);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}