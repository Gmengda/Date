#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    double z = 0;
//    int a = 0, b = 0;
//    int m[2] = { 0 };
//    int n = (nums1Size + nums2Size) / 2;
//    for (int i = 0; i < n - 1; i++)
//    {
//        if (nums1[a] > nums2[b])
//        {
//            if (b == nums2Size - 1)
//            {
//                nums2[b] = nums1[a];
//                a++;
//            }
//            else
//            {
//                b++;
//            }
//        }
//        else
//        {
//            if (a == nums1Size - 1)
//            {
//                nums1[a] = nums2[b];
//                b++;
//            }
//            else
//            {
//                a++;
//            }
//        }
//    }
//    if (n == 0)
//    {
//        if (nums1Size == 1)
//        {
//            m[0] = nums1[0];
//            m[1] = nums1[0];
//        }
//        else
//        {
//            m[0] = nums2[0];
//            m[1] = nums2[0];
//        }
//    }
//    else
//    {
//        if (nums1Size != 0 && nums2Size != 0)
//        {
//            if (nums1[a] > nums2[b])
//            {
//                m[1] = nums1[a];
//                m[0] = nums2[b];
//            }
//            else
//            {
//                m[0] = nums1[a];
//                m[1] = nums2[b];
//            }
//        }
//        else if (nums1Size == 0)
//        {
//            if (nums1[1] > nums1[0])
//            {
//                m[1] = nums1[1];
//                m[0] = nums1[0];
//            }
//            else
//            {
//                m[0] = nums1[1];
//                m[1] = nums1[0];
//            }
//        }
//        else if (nums2Size == 0)
//        {
//            if (nums1[1] > nums1[0])
//            {
//                m[1] = nums2[1];
//                m[0] = nums2[0];
//            }
//            else
//            {
//                m[0] = nums2[1];
//                m[1] = nums2[0];
//            }
//        }
//    }
//    if ((nums1Size + nums2Size) % 2 == 0)
//    {
//        z = (m[0] + m[1]) / 2.0;
//    }
//    else
//    {
//        z = m[1];
//    }
//    return z;
//}

double findMedianSortedArrays(int* a, int n, int* b, int m) {
    if (n == 0 && m == 1)
    {
        return b[m];
    }
    if (n == 1 && m == 0)
    {
        return a[n];
    }
    int len = n + m;
    int arr[1000];
    int i = 0;
    int j = 0;
    double out;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            arr[i + j] = a[i];
            i++;
        }
        else
        {
            arr[i + j] = b[j];
            j++;
        }
    }
    while (i < n)
    {
        arr[i + j] = a[i];
        i++;
    }
    while (j < m)
    {
        arr[i + j] = b[j];
        j++;
    }
    if (len % 2 == 0)
    {
        out = (arr[len / 2] + arr[len / 2 - 1]) / 2.0;
    }
    else
    {
        out = arr[len / 2];
    }
    return out;
}

int main()
{

    int a[100];
    int b[100];
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 0;i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("%lf", findMedianSortedArrays(a, n, b, m));
    return 0;
}
