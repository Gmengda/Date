#define _CRT_SECURE_NO_WARNINGS 1
#include "HPsort.h"

void topfile(const char* file,int k)
{
	int* b = (int*)malloc(sizeof(int) * k);
	if (b == NULL)
	{
		perror("topdile malloc");
		return;
	}
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("TOPfile fopen");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &b[i]);
	}
	createHP(b, k);
	for (int i = 0; i < 10000; i++)
	{
		int x;
		fscanf(fout, "%d", &x);
		if (x > b[0])
		{
			swap(&x, &b[0]);
			down(b,k,0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", b[i]);
	}

	fclose(fout);
}

void createfile()
{
	srand(time(0));
	int b[30];
	const char* name = "2023.3.30.txt";
	FILE* tmp = fopen(name, "w");
	if (tmp == NULL)
	{
		perror("file open");
		return;
	}
	
	for (int i = 0; i < 10000; i++)
	{
		int x = rand() % 10000;
		fprintf(tmp,"%d\n", x);
	}
	
	
	

	fclose(tmp);
}

int main()
{
	//int a[13] = { 452,458,48,15,98,46,57,12,5,369,54,1,10 };
	//int b[16] = { 156,546,85,3,1,4895,45,652,84,31,5,8,456,25,45,11 };
	////createHP(&b, 16);

	//int* c = Topn(a, 13, 5);

	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d ", c[i]);
	//}
	//createfile();
	topfile("2023.3.30.txt",30);
	return 0;
}