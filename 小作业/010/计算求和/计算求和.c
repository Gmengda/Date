#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int SUM(int a, int c)
{
	int m = a;
	int sum = 0;
	for (int i = 0; i < c; i++)
	{
		sum += a;
		a = a * 10;
		a += m;
	}
	return sum;
}

int main()
{

	int a = 0;
	int c = 0;

	scanf("%d %d", &a, &c);
	int sum = SUM(a, c);

	printf("%d", sum);

	return 0;
}