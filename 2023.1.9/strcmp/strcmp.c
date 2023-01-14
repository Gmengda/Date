#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int my_strcmp(char* m, char* n)
{
	assert(m && n);
	while (*m == *n)
	{
		if (*n == 0)
		{
			return 0;
		}
		m++;
		n++;
	}
	if (*m > *n)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 0;
}

int main()
{
	
	return;
}