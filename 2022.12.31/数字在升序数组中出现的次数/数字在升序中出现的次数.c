#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int getnumberofk(int* data, int datalen, int k) {
//    // write code here
//    int m = 0;
//
//    for (int i = 0; i < datalen; i++, data++)
//    {
//        if (*data == k)
//        {
//            m++;
//        }
//    }
//    return m;
//}

int GetNumberOfK(int* data, int dataLen, int k) {
	// write code here
	int m = 0;
	int n = dataLen - 1;

	if (data[0] == k && dataLen == 1)
	{
		return 1;
	}

	while (m < n)
	{

		if (data[m] == k && data[n] == k)
		{
			return n - m + 1;
		}
		if (data[m] != k)
		{
			m++;
		}
		if (data[n] != k)
		{
			n--;
		}
	}
	return 0;
}

int main()
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
			ch = ch - 'a' + 'A';
		putchar(ch);
	}
	printf("\n");
	return 0;
}