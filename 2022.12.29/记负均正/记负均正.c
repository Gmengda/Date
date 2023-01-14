#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m;
	int num = 0;

	while (scanf("%d", &m) != EOF)
	{
		int i = 0, a = 0;
		float j = 0;

		for (int n = 0; n < m; n++)
		{
			scanf("%d", &num);
			if (num < 0)
			{
				i++;
			}
			else if (num > 0)
			{
				a++;
				j += num;
			}
		}
		if (0 == a)
		{
			printf("%d 0.0\n", i);
		}
		else
		{
			printf("%d %.1f\n", i, j / a);
		}
	}
	return 0;
}

