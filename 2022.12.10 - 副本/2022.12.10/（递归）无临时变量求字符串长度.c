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

//�ַ�ָ�� + 1�������һ���ַ�
//����ָ�� + 1�������4���ֽ�

int main() {

	char arr[20];

	scanf("%[^\n]", &arr);
	printf("%d", my_strlen(arr));

	return 0;
}
