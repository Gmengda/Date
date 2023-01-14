#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct student
{
	char z[20];
	int s;
	int k;
};
int main()
{
	int i, j, n, m, k;

	scanf("%d\n", &n);

	struct student a[1001];

	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d\n", a[i].z, &a[i].s, &a[i].k);
	}

	scanf("%d\n", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d", &k);
		for (j = 0; j < n; j++)
		{
			if (a[j].s == k)
			{
				printf("%s %d\n", a[j].z, a[j].k);
			}
		}
	}

	return 0;
}