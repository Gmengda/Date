#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

union p
{
	char c;
	int i;
};

int main()
{
	union p s;
	s.i = 1;
	if (s.c == 1)
	{
		printf("С��");
	}
	else
	{
		printf("���");
	}
	return 0;
}