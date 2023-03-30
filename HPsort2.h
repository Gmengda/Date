#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//交换
void swap(int* a, int* b);

//建堆
void createHP(int* m,int node);

//向上调整
void push(int* m, int child);

//向下调整
void down(int* m, int size, int parent);

//取前k项最大数
int* Topn(int* m, int size, int k);
