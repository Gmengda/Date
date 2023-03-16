#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"


DL* NewNode(DListData x)
{
	DL* m = (DL*)malloc(sizeof(DL));
	if (m == NULL)
	{
		perror("malloc :");
		return NULL;
	}
	m->m = x;
	m->next = NULL;
	m->prve = NULL;

}

DL* InitDList()
{

	DL* m = NewNode(0);
	m->next = m;
	m->prve = m;

	return m;
}


void DListPrint(DL* m)
{
	DL* s = m;
	printf("<-> head <->");
	m = m->next;
	while (m != s)
	{
		printf(" %d <->", m->m);
		m = m->next;
	}
	printf("\n");
}

void DListendpush(DL* m, DListData x)
{
	DL* move = m->prve;
	DL* node = NewNode(x);

	move->next = node;
	node->prve = move;
	node->next = m;
	m->prve = node;
	
}

void DListendpop(DL* m)
{
	assert(m);
	DL* move = m->prve->prve;
	DL* s = m->prve;
	move->next = m;
	m->prve = move;

	free(s);
}


void DListheadpush(DL* m, DListData x)
{
	DL* move = m->next;
	DL* node = NewNode(x);

	node->prve = m;
	node->next = move;
	move->prve = node;
	m->next = node;

}

void DListheadpop(DL* m)
{
	assert(m);
	DL* s = m->next;
	DL* move = m->next->next;

	m->next = move;
	move->prve = m;

	free(s);


}
