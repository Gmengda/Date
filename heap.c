#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"




int main()
{
	HP m;
	HeapCreate(&m);
	HeapPush(&m, 1);
	HeapPush(&m, 9);
	HeapPush(&m, 5);
	HeapPush(&m, 8);
	HeapPush(&m, 12);
	HeapPush(&m, 13);
	HeapPush(&m, 7);
	HeapPush(&m, 4);
	
	while (HeapEmpty(&m))
	{
		printf("%d ", HeapTop(&m));
		HeapPop(&m);
	}
	HeapDestory(&m);
	return 0;
}













