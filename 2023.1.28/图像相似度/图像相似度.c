#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m = 0;
	int n = 0;
	int a[100][100] = { 0 }, b[100][100] = { 0 };
	scanf("%d%d", &m, &n);
	int i = 0;
	int j = 0;
	int count = 0.0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
		scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == b[i][j])
			{
				count++;
			}
		}
	}

	printf("%.2f\n", 100.0 * count / (m * n));
	return 0;
}