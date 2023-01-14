#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int c[100000];

int* printNumbers(int n, int* returnSize)
{
	int z = 1;
	while (n--)
	{
		z *= 10;
	}
	
	for (int i = 1; i < z; i++)
	{
		c[i - 1] = i;
	}

	return c;
}

int main()
{
	int n;
	int* q = NULL;

	printf("ÇëÊäÈëÕûÊý£º");
	scanf("%d", &n);

	printNumbers(n, q);

	int z = 1;
	while (n--)
	{
		z *= 10;
	}
	for (int i = 0; i < z - 1; i++)
	{
		printf("%d ", c[i]);
	}
	return 0;
}
