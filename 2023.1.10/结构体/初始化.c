#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct P
{
	char a;
	int b;
	char c;
};

struct S
{
	char a;
	char b;
	int c;
};

int main()
{

	struct S s1 = { 1,'2',{3,4},5.6f };   //��ʼ��
	struct S s2 = { .z = 6.6f };         //�����ʼ��
	return 0;
}