#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct student
{
	int num;
	char name[32];
	float score;
}stu;
//stu是结构体变量

typedef struct Student
{
	int num;
	char name[32];
	float score;
}Stu;
//Stu是类型



int main()
{
	Stu s1;

	return 0;
}







