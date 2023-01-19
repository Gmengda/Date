#define _CRT_SECURE_NO_WARNINGS 1

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0)
    {
        return 0;
    }
    int m = 1;
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            nums[m] = nums[i + 1];
            m++;
        }
    }
    return m;
}