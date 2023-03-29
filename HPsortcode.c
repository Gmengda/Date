#define _CRT_SECURE_NO_WARNINGS 1
#include "HPsort.h"

int main()
{
	int a[13] = { 452,458,48,15,98,46,57,12,5,369,54,1,10 };
	int b[16] = { 156,546,85,3,1,4895,45,652,84,31,5,8,456,25,45,11 };
	//createHP(&b, 16);

	int* c = Topn(a, 13, 5);

	for (int i = 0; i < 5; i++)
	{
		printf("%d ", c[i]);
	}

	return 0;
}