#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

int main()
{
	SL* m;
	SLinit(&m);

	SLpush(&m, 1);
	SLpush(&m, 2);
	SLpush(&m, 3);
	SLpush(&m, 4);
	SLpush(&m, 5);

	while (!SLexist(&m))
	{
		printf("%d ", SLshow(&m));
		SLpop(&m);
	}
	SLdestory(&m);
	return 0;
}