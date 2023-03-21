#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void SLinit(SL* m)
{
	assert(m);
	StackDate* tmp = (StackDate*)malloc(sizeof(StackDate) * 4);
	if (tmp == NULL)
	{
		perror("init malloc");
		return;
	}
	m->m = tmp;
	m->capacity = 4;
	m->top = 0;
}

void SLdestory(SL* m)
{
	assert(m);
	free(m->m);
	m->m = NULL;
	
	m->capacity = 0;
	m->top = 0;
}


void SLpush(SL* m, StackDate x)
{
	assert(m);
	if (m->capacity == m->top)
	{
		StackDate tmp = (StackDate*)realloc(m->m, sizeof(StackDate) * m->capacity * 2);
		if (tmp == NULL)
		{
			perror("init malloc");
			return;
		}
		m->m = tmp;
		m->capacity *= 2;
	}
	m->m[m->top] = x;
	m->top++;
}

void SLpop(SL* m)
{
	assert(m);
	assert(!SLexist(m));
	m->top--;
}


int SLshow(SL* m)
{
	assert(m);
	assert(!SLexist(m));
	return m->m[m->top - 1];
}

bool SLexist(SL* m)
{
	assert(m);
	return m->top == 0;
}