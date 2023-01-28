#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int i = 0;
		for (i = 1; i <= n; i++)
		{
			int j = 0;
			for (j = 1; j <= i; j++)
			{
				printf("%d ", j);
			}
			printf("\n");
		}
	}
	return 0;
}