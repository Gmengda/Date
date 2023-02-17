#include<stdio.h>

void swap(int* arr, int n, int m)
{
    while(n < m)
    {
        int f = arr[n];
        arr[n] = arr[m - 1];
        arr[m - 1] = f;
        n++;
        m--;
    }
}
 
 
void rotate(int* nums, int numsSize, int k){
 
 
    if(numsSize == 1)
    {
        return;
    }
 
 
    k = k % numsSize;
 
 
    swap(nums,0,numsSize);
    swap(nums,0,k);
    swap(nums,k,numsSize);
}