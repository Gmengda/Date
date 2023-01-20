#define _CRT_SECURE_NO_WARNINGS 1

int removeElement(int* nums, int numsSize, int val) {
    int n = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] != val)
        {
            nums[n] = nums[i];
            n++;
        }
    }
    return n;
}

int removeElement(int* nums, int numsSize, int val) {
    int left = 0, right = numsSize;

    while (left < right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right - 1];
            right--;
        }
        else
        {
            left++;
        }
    }

    return left;
}