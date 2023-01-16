#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//·ÇµÝ¹é
int count(int n)
{
	int c = 0;
	int m = 1;

	for (int i = 0; i < 32; i++)
	{
		if ((n & m) == m)
		{
			c++;
		}
		m = m << 1;
	}
	return c;
}

//µÝ¹é
int r_count(int n)
{
	int c = 2147483648;

	if (n != 0)
	{
		if ((n & c) == c)
			return 1 + r_count(n << 1);
		else
			return 0 + r_count(n << 1);
	}
	else
	{
		return 0;
	}
}


int main() 
{

	int a = -15;

	//printf("%d\n", count(a));
	printf("%d\n", r_count(a));

	return 0;
}