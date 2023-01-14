#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int my_strlen(char* arr) {

	if (*arr != '\0') 
	{
		return 1 + my_strlen(arr + 1);
	}
	else 
	{
		return 0;
	}

}

//字符指针 + 1，向后跳一个字符
//整形指针 + 1，向后跳4个字节

int main() {

	char arr[20];

	scanf("%[^\n]", &arr);
	printf("%d", my_strlen(arr));

	return 0;
}
