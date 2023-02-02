#include <stdio.h>
#include <stdlib.h>
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* m = (int*)malloc(sizeof(int)*1000);
    int n = 0;
    int nn = 0;
    int z[1000] = { 0 };

    for(int i = 0 ; i < nums1Size ; i++)
    {
        int a = i;
        for(int j = 0 ; j < nums2Size ; j++)
        {
            int b = j;
            if(nums1[a] == nums2[b])
            {
                z[nn] = nums1[a];
                nn++;
                a++;
                if(j == nums2Size - 1)
                {
                    goto too;
                }
                if(i == nums1Size - 1)
                {
                    goto too;
                }
            }
            else
            {
                too:
                if(nn > n)
                {
                    for(int p = 0 ; p < nn ; p++)
                    {
                        m[p] = z[p];
                    }
                    n = nn;
                    nn = 0;
                    break;
                }
            }
        }
    }
    *returnSize = n;

    return m;
}

int main()
{
    int n[] = {1,2};
    int m[] = {2,1};
    int s = 0;
    int* z = intersect(n,2,m,2,&s);
    for(int i = 0 ; i < s ; i++)
    {
        printf("%d ",z[i]);
    }
    return 0;
}