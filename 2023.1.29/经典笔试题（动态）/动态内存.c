#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////void GetMemory(char* p)    //�������� str �� p û���κι�ϵ
//////{						 //������ʱ��strcmp������ʱ���ǿ�ָ��
//////	p = (char*)malloc(100);//Ҳ������ڴ�й¶
//////}
//////void Test(void)
//////{
//////	char* str = NULL;
//////	GetMemory(str);
//////	strcpy(str, "hello world");
//////	printf(str);
//////}
////
////
////char* GetMemory(void)
////{
////	char p[] = "hello world";   //�ֲ���������
////	return p;				 //����ջ�ռ��ַ������
////}
////void Test(void)
////{
////	char* str = NULL;
////	str = GetMemory();         //�Ƿ������ڴ�
////	printf(str);
////}
//
//
//
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);              //�ڴ�й©
//}


void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}