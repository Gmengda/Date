#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//·ÇµÝ¹é
int count(int n,int m)
{
	int c = 0;
	int t = 1;

	for (int i = 0; i < 32; i++)
	{
		if ((n & t) != (m & t))
		{
			c++;
		}
		t = t << 1;
	}
	return c;
}

int main()
{

	int a = 188;
	int b = 77;

	printf("%d\n", count(a,b));

	return 0;
}