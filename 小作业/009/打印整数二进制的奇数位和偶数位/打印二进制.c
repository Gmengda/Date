#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//�ǵݹ�
void print(int n)
{

	for (int i = 31; i >= 0; i--)
	{
		printf("%d ", (n >> i) & 1);
	}

}

int main()
{

	int a = 15;

	printf("������:");
	print(a);

	printf("\n����λ:");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}

	printf("\nż��λ:");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (a >> i) & 1);
	}

	return 0;
}
