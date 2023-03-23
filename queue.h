#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Queuedatetype;

typedef struct QueueNode
{
	struct QueueNode* next;
	Queuedatetype m;
}QNode;


typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int Size;
}Q;

void Queueinit(Q* m);

void Queuedestory(Q* m);

void Queuepush(Q* m, Queuedatetype x);

void Queuepop(Q* m);

int Queuesize(Q* m);

bool QueueEmpty(Q* m);

Queuedatetype Queuefort(Q* m);

Queuedatetype Queuetail(Q* m);





