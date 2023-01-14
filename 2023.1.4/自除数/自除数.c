#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int* selfDiv(int left, int right, int* returnSize) {
	int m[10000] = { 0 };

	for (; left < right; left++)
	{
		int num = left;
		while (num)
		{
			if (num % 10 == 0)
			{
				break;
			}
			if ((left % (num % 10)) != 0)
			{
				break;
			}
			num /= 10;
		}
		if (num == 0)
		{
			m[*returnSize] = left;
			(*returnSize)++;
		}
	}
	return m;
}

int main()
{
	int left, right;
	int m = 0;
	scanf("%d %d", &left, &right);

	int* arr = selfDiv(left, right, &m);

	for (int i = 0; i < m; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}