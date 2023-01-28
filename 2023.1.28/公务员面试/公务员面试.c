#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i = 0;
	int sum = 0;
	int min = 100;
	int max = 0;
	int score = 0;
	for (i = 0; i < 7; i++)
	{
		scanf("%d ", &score);
		sum += score;//ÇóºÍ
		if (score > max)
			max = score;
		if (score < min)
			min = score;
	}
	printf("%.2f\n", (sum - min - max) / 5.0);
	return 0;
}