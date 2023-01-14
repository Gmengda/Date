#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void my_setcpy(char* m, char* n)
//{
//	while (*n != '\0')
//	{
//		*m++ = *n++;
//	}
//	*m = *n;
//}

//void my_setcpy(char* m, char* n)
//{
//	while (*m++ = *n++)
//	{
//		;
//	}
//}

//void my_setcpy(char* m, char* n)
//{
//	/*assert(m != NULL);
//	assert(m != NULL);*/
//	assert(m && n);//断言指针的有效性
//	while (*m++ = *n++)
//	{
//		;
//	}
//}

//void my_setcpy(char* m,const char* n)
//{
//	assert(m && n);//断言指针的有效性
//	while (*m++ = *n++)
//	{
//		;
//	}
//}

char* my_strcpy (char* m,const char* n)
{
	assert(m && n);//断言指针的有效性
	while (*m++ = *n++)
	{
		;
	}
	return m;
}

int main() 
{

	char m[20] = { 0 };
	char n[] = "hellomin";

	my_strcpy(m, n);
	printf("%s", m);

	return 0;
}