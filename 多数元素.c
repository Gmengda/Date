int cmp(const void* a, const void* b)
 {
     return *(int*)a - *(int*)b;
 }
int* majorityElement(int* nums, int numsSize, int* returnSize){
    if(numsSize==1){
        return nums;
    }
    qsort(nums,numsSize,sizeof(int),cmp);
    int *ans=malloc(sizeof(int)*2);
    int sum=0,num=0,now=nums[0],flag=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]==now)
            sum++;
        else{
            now=nums[i];
            sum=1;
            flag=0;
        }
        if(sum>numsSize/3&&flag==0){
            ans[num]=nums[i];
            num++;
            flag=1;
        }
    }
    *returnSize=num;
    return ans;
}