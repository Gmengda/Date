#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	char arr[3][3] = { 0 };
	int i = 0;
	int j = 0;
	char flag = 'c';
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%c", &arr[i][j]);
			getchar();
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
		{
			flag = arr[i][1];
			break;
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i])
		{
			flag = arr[1][i];
			break;
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
	{
		flag = arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
	{
		flag = arr[1][1];
	}
	if (flag == 'K')
		printf("KiKi wins!");
	else if (flag == 'B')
		printf("BoBo wins!");
	else
		printf("No winner!");
	return 0;
}