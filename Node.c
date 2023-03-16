#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"

void text1()
{
	DL* m = InitDList();

	DListendpush(m, 1);
	DListendpush(m, 2);
	DListendpush(m, 3);
	DListendpush(m, 4);
	DListendpop(m);

	DListPrint(m);

}

void text2()
{
	DL* m = InitDList();

	DListheadpush(m, 1);
	DListheadpush(m, 2);
	DListheadpush(m, 3);
	DListheadpush(m, 4);

	DListheadpop(m);
	DListPrint(m);
	DListheadpop(m);
	DListPrint(m);
	DListheadpop(m);
	DListPrint(m);
	DListheadpop(m);
	DListPrint(m);

}

int main()
{
	

	text2();

	return 0;
}