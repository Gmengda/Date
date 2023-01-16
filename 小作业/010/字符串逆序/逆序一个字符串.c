#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int strlen(char arr[])
{
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}

void swap(char arr[],int sz)
{
	char* pa = &arr[0];
	char* pc = &arr[sz - 1];
	while (pc - pa > 0)
	{
		char m = *pa;
		*pa = *pc;
		*pc = m;
		pa++;
		pc--;
	}
}

int main()
{

	char arr[] = "hello bit";
	int sz = strlen(arr);

	swap(arr,sz);
	printf("%s", arr);

	return 0;
}