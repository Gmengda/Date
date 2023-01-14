#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int m;
	/*while (scanf("%d", &m) != EOF)
	{
		int z = 2;
		int sum = 0;

		for (int i = 0; i < m; i++)
		{
			sum += z;
			z += 3;
		}
		printf("%d", sum);
		printf("\n");
	}*/
	while (scanf("%d", &m) != EOF)
	{
		printf("%d", 2 * m + m * (m - 1) * 3 / 2);
	}
	return 0;
}