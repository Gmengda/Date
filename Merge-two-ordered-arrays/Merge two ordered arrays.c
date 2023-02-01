#include <stdlib.h>

int cro(const void* a,const void* b)
{
    return *(int*)a-*(int*)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = m ; i < nums1Size ; i++)
    {
        nums1[i] = nums2[i - m];
    }
    qsort(nums1,nums1Size,sizeof(nums1[0]),cro);

}