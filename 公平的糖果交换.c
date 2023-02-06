#include <stdio.h>
#include <stdlib.h>

int cor(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize){
    int* m = (int*)malloc(sizeof(int) * 2);
    int a = 0;
    int b = 0;
    int flag = 0;
    for(int i = 0 ; i < aliceSizesSize ; i++)
    {
        a += aliceSizes[i];
    }
    for(int i = 0 ; i < bobSizesSize ; i++)
    {
        b += bobSizes[i];
    }
    if(a > b)
    {
        for(int i = 0 ; i < aliceSizesSize ; i++)   
        {
            for(int j = 0 ; j < bobSizesSize ; j++)
            {
                if(aliceSizes[i] - bobSizes[j] == (a - b) / 2)
                {
                    m[0] = aliceSizes[i];
                    m[1] = bobSizes[j];
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
    }
    else
    {
        for(int i = 0 ; i < aliceSizesSize ; i++)   
        {
            for(int j = 0 ; j < bobSizesSize ; j++)
            {
                if(aliceSizes[i] - bobSizes[j]  == (a - b) / 2)
                {
                    m[0] = aliceSizes[i];
                    m[1] = bobSizes[j];
                    flag = 1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
    }
    *returnSize = 2;
    return m;
}
int main()
{
    int m[] = {1,2,3};
    int n[] = {2};
    findRadius(m,3,n,1);

    return 0;
}