#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//·ÇµÝ¹é
void Swap(int arr1[], int arr2[], int sz)
{
    while(sz--)
    {
        int m = arr1[sz];
        arr1[sz] = arr2[sz];
        arr2[sz] = m;
    }
}

//µÝ¹é
void swap(int arr1[], int arr2[], int sz)
{

    if (sz >= 0)
    {
        int m = arr1[sz];
        arr1[sz] = arr2[sz];
        arr2[sz] = m;
        swap(arr1, arr2, sz - 1);
    }

}

int main()
{
    int arr1[] = { 1,2,3,4,5,6 };
    int arr2[] = { 4,5,6,7,8,9 };
    int sz = sizeof(arr1) / sizeof(arr1[0]);

    swap(arr1, arr2, sz);

    for (int i = 0; i < sz; i++) 
    {
        printf("%d", arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < sz; i++)
    {
        printf("%d", arr2[i]);
    }
    return 0;
}