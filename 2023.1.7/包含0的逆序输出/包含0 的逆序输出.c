#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int m = 0;

	scanf("%d", &m);
	
	if (m == 0)
	{
		printf("0");
	}

	while (m != 0)
	{
		printf("%c", (48 + m % 10));
		m /= 10;
	}

	return 0;
}