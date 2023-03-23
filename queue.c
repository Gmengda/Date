#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"


void Queueinit(Q* m)
{
	assert(m);
	m->head = NULL;
	m->tail = NULL;
	m->Size = 0;
}

void Queuedestory(Q* m)
{
	assert(m);
	QNode* tem = m->head;
	while (tem)
	{
		QNode* move = tem->next;
		free(tem);
		tem = move;
	}
	m->head = NULL;
	m->Size = 0;
	m->tail = NULL;
}

void Queuepush(Q* m, Queuedatetype x)
{
	assert(m);
	QNode* tem = (QNode*)malloc(sizeof(QNode));
	if (tem == NULL)
	{
		perror("push malloc");
		return;
	}
	tem->next = NULL;
	tem->m = x;
	if (m->head == NULL)
	{
		assert(m->tail == NULL);
		m->head = tem;
		m->tail = tem;
	}
	else
	{
		m->tail->next = tem;
		m->tail = tem;
	}
	m->Size++;
}

void Queuepop(Q* m)
{
	assert(m);
	assert(m->head != NULL);
	if (m->head->next == NULL)
	{
		free(m->head);
		m->head = m->tail = NULL;
	}
	else
	{
		QNode* tem = m->head->next;
		free(m->head);
		m->head = tem;
	}
	m->Size--;
}


int Queuesize(Q* m)
{
	assert(m);
	return m->Size;
}

bool QueueEmpty(Q* m)
{
	assert(m);

	return m->Size == 0;
}

Queuedatetype Queuefort(Q* m)
{
	assert(m);
	assert(!QueueEmpty(m));
	return m->head->m;
}

Queuedatetype Queuetail(Q* m)
{
	assert(m);
	assert(!QueueEmpty(m));
	return m->tail->m;
}




