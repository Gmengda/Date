#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void Pop(int a)
{
	int m = a;
	while (m > 1)
	{
		a = a + m / 2;
		m = m / 2 + m % 2;
	}
	printf("%d", a);
}

int main()
{
	int a = 0;

	scanf("%d", &a);

	Pop(a);

	return 0;
}