#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct student
{
	int num;
	char name[32];
	float score;
}stu;
//stu�ǽṹ�����

typedef struct Student
{
	int num;
	char name[32];
	float score;
}Stu;
//Stu������



int main()
{
	Stu s1;

	return 0;
}







