#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

int my_strlen(const char* m)
{
	int i = 0;
	assert(m);//断言指针的有效性
	while (*m++ != '\0')
	{
		i++;
	}
	return i;
}

int main()
{

	char m[20] = "hellomin";
	char n[] = "hellomin";

	printf("%d", my_strlen(m));
	return 0;
}