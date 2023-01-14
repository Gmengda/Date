#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int c[1000];
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = 0;
    int a[1000] = { 0 };
    int b[1000] = { 0 };

    for (int i = 0; i < nums1Size; i++)
    {
        if (a[nums1[i]] == 0)
        {
            a[nums1[i]]++;
        }
    }
    for (int i = 0; i < nums2Size; i++)
    {
        if (b[nums2[i]] == 0)
        {
            b[nums2[i]]++;
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        if (a[i] + b[i] == 2)
        {
            c[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return c;
}

int main()
{
	int a[1000], b[1000];
	int z[1000];
	int n, m;
    int s = 0;
	scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    intersection(a, n, b, m, &s);
    for (int i = 0; i < s; i++)
    {
        printf("%d ", c[i]);
    }
	return 0;
}