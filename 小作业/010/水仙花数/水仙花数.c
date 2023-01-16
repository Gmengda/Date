#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

void daffodils(int n)
{
	int count = 1;
	int m = n;
	int sum = 0;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	n = m;
	while (n)
	{
		sum += pow(n % 10, count);
		n = n / 10;
	}
	if (sum == m)
	{
		printf("%d ", sum);
	}
}

int main()
{
	for (int i = 1; i < 100000; i++)
	{
		daffodils(i);
	}
	return 0;
}