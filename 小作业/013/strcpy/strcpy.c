#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

char* my_strcpy(char* m, const char* n)
{
	assert(m && n);//����ָ�����Ч��
	while (*m++ = *n++)
	{
		;
	}
	return m;
}

int main()
{

	char m[20] = { 0 };
	char n[] = "hellomin";

	my_strcpy(m, n);
	printf("%s", m);

	return 0;
}