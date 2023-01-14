#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main()
{
	char m[1000];
	int a[80] = { 0 };
	int i = 0;
	scanf("%[^\n]", &m);

	while (m[i] != '\0')
	{
		a[m[i] - '0']++;
		i++;
	}
	for (int j = 0; j < 80;)
	{
		if (a[j] != 0)
		{
			printf("%c", j + 48);
			a[j]--;
		}
		else
		{
			j++;
		}
	}

	return 0;
}