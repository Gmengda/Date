#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//////void GetMemory(char* p)    //传参问题 str 和 p 没有任何关系
//////{						 //待返回时候，strcmp拷贝的时候还是空指针
//////	p = (char*)malloc(100);//也会造成内存泄露
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
////	char p[] = "hello world";   //局部变量销毁
////	return p;				 //返回栈空间地址的问题
////}
////void Test(void)
////{
////	char* str = NULL;
////	str = GetMemory();         //非法访问内存
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
//	printf(str);              //内存泄漏
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