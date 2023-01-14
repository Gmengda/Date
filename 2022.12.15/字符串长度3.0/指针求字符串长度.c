#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int my_strlen(char* str)
//{
//	int count = 0;
//	while (*str != "\0")
//	{
//		count++;
//	}
//	return count;
//}

int my_strlen(char* str)
{
	char* star = str;
	while (*str != "\0")
	{
		str++;
	}
	return str - star;
}

int main()
{
	char arr[] = "bit hello";

	printf("%d", my_strlen(arr));

	return 0;
}