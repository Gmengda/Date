#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
int m = 0;//列
int n = 0;//行
int arr[10][10] = { 0 };
int cnt = 0;//操作的次数
char op = 0;//代表操作的字符
int a = 0;
int b = 0;
//读取数据
scanf("%d%d", &n, &m);
int i = 0;
int j = 0;
for (i = 0; i < n; i++)
{
	for (j = 0; j < m; j++)
	{
		scanf("%d", &arr[i][j]);
	}
}
scanf("%d", &cnt);
for (i = 0; i < cnt; i++)
{
	//读取操作指令
	//注释解释：
	//scanf("%d", &a);
	//scanf(" %c", &c); // 消耗 %d 后的所有后继空白符，然后读一个 char
	scanf(" %c %d %d", &op, &a, &b);
	//执行操作
	if (op == 'r')
	{
		//交换a和b行
		for (j = 0; j < m; j++)
		{
			int tmp = arr[a - 1][j];
			arr[a - 1][j] = arr[b - 1][j];
			arr[b - 1][j] = tmp;
		}
	}
	else if (op == 'c')
	{
		//交换a和b列
		for (j = 0; j < n; j++)
		{
			int tmp = arr[j][a - 1];
			arr[j][a - 1] = arr[j][b - 1];
			arr[j][b - 1] = tmp;
		}
	}
}
	//输出
	for (i = 0; i < n; i++)
	{
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}