#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
int m = 0;//��
int n = 0;//��
int arr[10][10] = { 0 };
int cnt = 0;//�����Ĵ���
char op = 0;//����������ַ�
int a = 0;
int b = 0;
//��ȡ����
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
	//��ȡ����ָ��
	//ע�ͽ��ͣ�
	//scanf("%d", &a);
	//scanf(" %c", &c); // ���� %d ������к�̿հ׷���Ȼ���һ�� char
	scanf(" %c %d %d", &op, &a, &b);
	//ִ�в���
	if (op == 'r')
	{
		//����a��b��
		for (j = 0; j < m; j++)
		{
			int tmp = arr[a - 1][j];
			arr[a - 1][j] = arr[b - 1][j];
			arr[b - 1][j] = tmp;
		}
	}
	else if (op == 'c')
	{
		//����a��b��
		for (j = 0; j < n; j++)
		{
			int tmp = arr[j][a - 1];
			arr[j][a - 1] = arr[j][b - 1];
			arr[j][b - 1] = tmp;
		}
	}
}
	//���
	for (i = 0; i < n; i++)
	{
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}