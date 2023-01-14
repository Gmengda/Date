#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Add(int num1, int num2) {
	int m;
	do{
		m = num1 & num2;
		m = m << 1;
		num1 = num1 ^ num2;
		num2 = m;
	}
	while (m != 0);
	return num1;
}

int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", Add(a, b));
	}
	return 0;
}