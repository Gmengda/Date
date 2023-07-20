int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    int add = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            ans[add] = nums[i];
            add += 2;
        }
    }
    add = 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 1) {
            ans[add] = nums[i];
            add += 2;
        }
    }
    *returnSize = numsSize;
    return ans;
}