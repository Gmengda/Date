#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strlen(char* s)
{
	int i = 0;
	while (*s != 0)
	{
		i++;
		s++;
	}
	return i;
}

void voit(char* s)
{
	while (*s != 0)
	{
		if ((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z')){}
		else
		{
			*s = ' ';
		}
		*s++;
	}
}

void down(char* s, int n, int m)
{
	while (n < m)
	{
		char i = s[n];
		s[n] = s[m];
		s[m] = i;
		n++;
		m--;
	}
}

void rever(char* s, int n)
{
	int m = 0;
	char* a = s;
	for (int i = 0; i <= n; i++, a++)
	{
		if (*a == ' ' || *a == 0)
		{
			down(s, m, i - 1);
			m = i + 1;
		}
	}
}

int main()
{
	char s[10000];

	scanf("%[^\n]", s);
	int n = my_strlen(s);

	//×ª»»¼ä¸ô·û
	voit(s);
	//µ¹ÅÅµ¥´Ê
	rever(s, n);
	//µ¹ÅÅ¾ä×Ó
	down(s, 0, n - 1);


	printf("%s", s);

	return 0;
}