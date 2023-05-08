void swap(int * nums,int indexA,int indexB)
{
    int temp    = nums[indexA];
    nums[indexA]= nums[indexB];
    nums[indexB]= temp;
}

void prem(int* nums, int numsSize, int* returnSize, int** returnColumnSizes,int** returnNums,int offset)
{
    if(offset == numsSize)
    {
        //遍历到末尾了
        //申请returnNums
        returnNums[*returnSize] = (int *)malloc(sizeof(int ) * numsSize);
        //拷贝内容到returnNums
        memcpy(returnNums[*returnSize],nums,sizeof(int) * numsSize );
        //记录当前拷贝内容的长度
        (*returnColumnSizes)[*returnSize] = numsSize;
        *returnSize = *returnSize + 1;

    }
    else
    {

        //回溯算法的核心
        int i;
        for(i = offset; i < numsSize; i++)
        {
            swap(nums,i,offset);//i 和 offset 交换
            prem(nums,numsSize,returnSize,returnColumnSizes,returnNums,offset+1);
            swap(nums,i,offset);//i 和 offset 交换
        }
    }
}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    //不重复的数字的全排序
    //组合次数为 n！= n *( n - 1) *( n - 2) ...... 2 * 1
    //这样的方法适合回溯的方法
    //取值范围1 <= nums.length <= 6  = 6 * 5 * 4 * 3 *2 * 1 = 720中可能
    int **returnNums = (int **)malloc(sizeof(int *) * 721);
    *returnColumnSizes= (int *)malloc(sizeof(int ) * 721);
    *returnSize = 0;
    prem(nums,numsSize,returnSize,returnColumnSizes,returnNums,0);
    return returnNums;

}