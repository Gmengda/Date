int cor(const void* a,const void* b)
{
    return *(int*)b - *(int*)a;
}

int judge(const int a , const int b , const int c)
{
    if(a + b > c && b + c > a)
    {
        return 1;
    }
    return 0;
}

int largestPerimeter(int* nums, int numsSize){
    qsort(nums,numsSize,sizeof(int),cor);
    int m = 0;
    for(int a = 0 ; a < numsSize - 2 ; a++)
    {
        if(judge(nums[a],nums[a + 1],nums[a + 2]) && m < nums[a] + nums[a + 1] + nums[a + 2])
        {
            m = nums[a] + nums[a + 1] + nums[a + 2];
        }
    }
    return m;
}