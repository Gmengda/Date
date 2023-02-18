#include<stdio.h>

 int cmp(const void *pa, const void *pb) {
    return *(int *)pa - *(int *)pb;
}

double trimMean(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    int partialSum = 0;
    for (int i = arrSize / 20; i < (19 * arrSize / 20); i++) {
        partialSum += arr[i];
    }
    return partialSum / (arrSize * 0.9);
}