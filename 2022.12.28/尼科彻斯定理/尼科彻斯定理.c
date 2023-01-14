#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int m;
	int z;

	while (scanf("%d", &m) != EOF)
	{
		z = m * m - m + 1;

		printf("%d", z);

		for (int i = 1; i < m; i++)
		{
			z += 2;
			printf("+");
			printf("%d", z);
		}
		printf("\n");
	}
	return 0;
}