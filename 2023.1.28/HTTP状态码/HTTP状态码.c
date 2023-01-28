#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int s = 0;
	while (scanf("%d", &s) != EOF)
	{
		switch (s)
		{
		case 200:
			printf("OK\n");
			break;
		case 202:
			printf("Accepted\n");
			break;
		case 400:
			printf("Bad Request\n");
			break;
		case 403:
			printf("Forbidden\n");
			break;
		case 404:
			printf("Not Found\n");
			break;
		case 500:
			printf("Internal Server Error\n");
			break;
		case 502:
			printf("Bad Gateway\n");
			break;
		}
	}
	return 0;
}