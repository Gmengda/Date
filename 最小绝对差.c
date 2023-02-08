int cor(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){
    qsort(arr,arrSize,sizeof(arr[0]),cor);
    int m = 1000000;
    for(int i = 0 ; i < arrSize - 1 ; i++)
    {
        if( m < arr[i + 1] - arr[i])
        {
            m = arr[i + 1] - arr[i];
        }
    }

    int** a = (int**)malloc(sizeof(int*) * arrSize);
    int p = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * arrSize);
    for(int i = 0 ; i < arrSize - 1 ; i++)
    {
        if(arr[i+1] - arr[i] == m)
        {
            (*returnColumnSizes)[p] = 2;
            a[p] = (int*)malloc(sizeof(int) * 2);
            a[p][0] = arr[i];
            a[p][1] = arr[i + 1];
            p++;
        }
    }

    *returnSize = p;
    return a;
}