#define _CRT_SECURE_NO_WARNINGS 1

int findPeakElement(int* nums, int numsLen) {
    int i;
    for (i = 1; i < numsLen; i++)
    {
        if ((nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) || ((i == numsLen - 1 && nums[i] < nums[i + 1])))
        {
            return i;
        }
        else if (i == 1 && nums[i] < nums[i - 1])
        {
            return 0;
        }
    }
    return 0;
}