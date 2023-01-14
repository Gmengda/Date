#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>




int* findErrorNums(int* nums, int numsSize, int* returnSize) {

	/*int arr[10002] = { 0 };
	int* res = malloc(sizeof(int) * 3);

	for (int i = 0; i < numsSize; ++i) {
		arr[nums[i]]++;
		if (arr[nums[i]] == 2) res[0] = nums[i];
	}
	for (int i = 0; i < numsSize; ++i) {
		if (arr[i + 1] == 0) res[1] = i + 1;
	}
	*returnSize = 2;
	return res;*/

	returnSize = nums;
	nums++;
	
	for (int i = 0; i < numsSize; i++, nums++, returnSize++)
	{
		if (*returnSize == *nums)
		{
			*nums += 1;
			nums--;
			return nums;
		}
	}

}

int main()
{

	int arr[10000] = { 0 };
	int ar[10000] = { 0 };
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	int* z = findErrorNums(arr,n,ar);

	for (int i = 0; i < 2; i++)
	{
		printf("%d ", z[i]);
	}

		return 0;
}