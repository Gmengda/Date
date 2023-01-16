#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n, i, j, k;

	scanf("%d", &n);
	n = n / 2 + 1;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			printf("  ");
		}
		for (k = 0; k <= 2 * i; k++)
		{
			printf("%c ", '*');
		}
		printf("\n");
	}

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("  ");
		}
		for (k = 2 * (n - i - 1); k >= 0; k--)
		{
			printf("%c ", '*');
		}
		printf("\n");
	}
	return 0;
}