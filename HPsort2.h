#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


//����
void swap(int* a, int* b);

//����
void createHP(int* m,int node);

//���ϵ���
void push(int* m, int child);

//���µ���
void down(int* m, int size, int parent);

//ȡǰk�������
int* Topn(int* m, int size, int k);
