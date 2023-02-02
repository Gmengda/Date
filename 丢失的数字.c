#include <stdio.h>
#include <string.h>

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* m = (int*)malloc(sizeof(int) * 1000);
    int n = 0;
    int a[1000] = { 0 };
    for(int i = 0 ; i < nums1Size ; i++)
    {
        a[nums1[i]]++;
    }
    for(int i = 0 ; i < nums2Size ; i++)
    {
        if(a[nums2[i]] != 0)
        {
            a[nums2[i]] = 0;
            m[n] = nums2[i];
            n++;
        }
    }
    *returnSize = n;
    return m;
}