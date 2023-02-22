#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLArr;

typedef struct SeqList
{
	SLArr* m;				   // 元素
	int size;				   // 有效个数
	int capacity;              // 容量大小
}SL;						   // 重命名

//顺序表初始化
void SL_Init(SL* m);

//顺序表增加
void SL_Add(SL* m);

//顺序表删除
void SL_Del(SL* m);

//顺序表查找
void SL_searched(SL* m);

//顺序表修改
void SL_change(SL* m);

//顺序表输出
void SL_print(SL* m);









