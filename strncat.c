#include <stdio.h>
#include <windows.h>
#include <assert.h>
char *my_strncat(char *des, const char *src, int count)
{
	assert(des);
	assert(src);
	char *cat = des;
	int i = 0;
	while (*des != '\0')
	{
		des++;
	}
	for (; i <count; i++)
	{
		*des = *src;
		des++;
		*src++;
	}
	return cat;
}
 
int main()
{
	char a[10] = { 'a', 'b', 'c', '\0' };
	char b[20] = "world and bit";
	int n = 5;
	char *ret = my_strncat(a, b, n);
	printf("ret: %s\n", ret);
	system("pause");
	return 0;
}