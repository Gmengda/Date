#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


int main()
{
	Q m;
	Queueinit(&m);
	Queuepush(&m, 1);
	Queuepush(&m, 2);
	Queuepush(&m, 3);
	Queuepush(&m, 4);
	Queuepush(&m, 5);

	while (!QueueEmpty(&m))
	{
		printf("%d ", Queuefort(&m));
		Queuepop(&m);
	}
	Queuedestory(&m);
	return 0;
}
