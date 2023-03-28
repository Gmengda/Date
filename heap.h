#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int HPdatatype;

typedef struct Heap
{
	HPdatatype* m;
	int size;
	int capacity;
}HP;


// 堆的构建
void HeapCreate(HP* hp);


// 堆的销毁
void HeapDestory(HP* hp);


// 堆的插入
void HeapPush(HP* hp, HPdatatype* a);


// 堆的删除
void HeapPop(HP* hp);


// 取堆顶的数据
HPdatatype HeapTop(HP* hp);


// 堆的数据个数
int HeapSize(HP* hp);


// 堆的判空
bool HeapEmpty(HP* hp);

//排序
void Heapqsort(HP* hp);




