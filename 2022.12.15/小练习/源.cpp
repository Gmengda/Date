#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	char* pa = (char*)&arr[0];
	char* pc = (char*)&arr[9];
	printf("%d", pa - pc);
	return 0;
}


