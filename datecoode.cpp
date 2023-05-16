#define _CRT_SECURE_NO_WARNINGS 1
#include "date.h"


int main()
{
	Date m(2021, 3, 6);
	Date m2(2024,1,1);

	int c = m2 - m;

	cout << c << endl;

	return 0;
}