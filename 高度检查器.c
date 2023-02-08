int cor(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize){
    int m[100] = { 0 };
    int n = 0;
    for(int i = 0 ; i < heightsSize ; i++)
    {
        m[i] = heights[i];
    }
    qsort(heights,heightsSize,sizeof(int),cor);
    for(int i = 0 ; i < heightsSize ; i++)
    {
        if(m[i] != heights[i])
        {
            n++;
        }
    }

    return n;
}