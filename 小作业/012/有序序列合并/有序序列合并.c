#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//#include <stdio.h>
//int main()
//{
//    int a, b, c[100], temp;
//    scanf("%d", &a);
//    scanf("%d", &b);
//    for (int i = 1; i <= a + b; i++) {
//        scanf("%d", &c[i]);
//    }
//    for (int i = 1; i <= a + b; i++)
//    {
//        for (int j = 1; j <= a + b - i; j++)
//        {
//            if (c[j] > c[j + 1])
//            {
//                temp = c[j];
//                c[j] = c[j + 1];
//                c[j + 1] = temp;
//            }
//        }
//    }
//    for (int i = 1; i < a + b + 1; i++) {
//        printf("%d ", c[i]);
//    }
//    return 0;
//}

int main() {
    int a, b;
    int arr1[1000] = {0};
    int arr2[1000] = {0};

    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int* left = arr1;
    int* right = arr2;
    int q = 0;
    int p = 0;
    for (int i = 0; i < (a + b); i++)
    {
        if (p == a)
        {
            printf("%d ", *right);
            right++;
        }
        else if (q == b)
        {
            printf("%d ", *left);
            left++;
        }
        else if (*left > *right)
        {
            printf("%d ", *right);
            right++;
            q++;
        }
        else
        {
            printf("%d ", *left);
            left++;
            p++;
        }
    }

    return 0;
}