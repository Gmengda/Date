#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//
//#include<stdio.h>
//#include<assert.h>
//int pd(int* a, int n)
//{
//    assert(a && n);
//    int f1 = 1;
//    int f2 = 1;
//    int i = 0;
//    for (i = 0; i < n - 1; i++)
//    {
//        if (a[i] > a[i + 1])
//        {
//            f1 = 0;
//        }
//    }
//    for (i = 0; i < n - 1; i++)
//    {
//        if (a[i] < a[i + 1])
//        {
//            f2 = 0;
//        }
//    }
//    return (f1 || f2);
//}
//
//int main()
//{
//    int a[50];
//    int i, N;
//    scanf("%d", &N);
//    for (i = 0; i < N; i++)
//    {
//        scanf("%d ", &a[i]);
//    }
//    if (pd(a, N))
//    {
//        printf("sorted\n");
//    }
//    else
//    {
//        printf("unsorted\n");
//    }
//    return 0;
//}

int main() {
    int m;
    int arr[100];
    int j = 0;

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m - 2; i++)
    {
        if ((arr[i] > arr[i + 1] && arr[i + 1] < arr[i + 2]) || (arr[i] < arr[i + 1] && arr[i + 1] > arr[i + 2]))
        {
            j = 1;
            break;
        }
    }
    if (j)
    {
        printf("unsorted");
    }
    else
    {
        printf("sorted");
    }
    return 0;
}