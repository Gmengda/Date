#define _CRT_SECURE_NO_WARNINGS 1

int searchInsert(int* nums, int numsSize, int target) {
    int a = 0;
    int b = numsSize;
    int z = 0;
    while (a < b)
    {
        if (a == b - 1)
        {
            if (nums[a] < target)
            {
                return b;
            }
            else
            {
                return a;
            }
        }
        z = (a + b) / 2;
        if (nums[z] > target)
        {
            b = z;
        }
        else if (nums[z] < target)
        {
            a = z;
        }
        else
        {
            return z;
        }
    }
    return z;
}