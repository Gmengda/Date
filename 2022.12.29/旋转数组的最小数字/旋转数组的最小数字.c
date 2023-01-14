#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int minnumberinrotatearray(int* rotatearray, int rotatearraylen) {
	int n = *rotatearray;
	int m = 0;
	for (int i = 0; i < rotatearraylen; i++, rotatearray++)
	{

		if ((m > *rotatearray) && (rotatearraylen != 1))
		{
			return *rotatearray;
		}
		else if ((i == (rotatearraylen - 1)) || (1 == rotatearraylen))
		{
			return n;
		}
		m = *rotatearray;
	}
	return 0;
}

int main()
{

	int n = 0;
	int a[10000] = { 0 };

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if ((a[i] > a[i + 1]) && (n != 1))
		{
			printf("%d", a[i + 1]);
			break;
		}
		else if ((i == (n - 2)) || (1 == n))
		{
			printf("%d", a[0]);
			break;
		}
	}
	return 0;
}