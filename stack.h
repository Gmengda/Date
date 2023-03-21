#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackDate;

typedef struct StackList
{
	StackDate* m;
	int top;
	int capacity;
}SL;

void SLinit(SL* m);

void SLdestory(SL* m);


void SLpush(SL* m, StackDate x);

void SLpop(SL* m);


int SLshow(SL* m);

bool SLexist(SL* m);




