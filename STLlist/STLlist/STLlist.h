#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int STLlistDateNode;

typedef struct STLlist
{
    STLlistDateNode m;
    struct STLlist* point;
}STL;

//打印单向链表
void STLlistPrint(struct STLlist* mtp);

//尾插
void STL_push_end(struct STLlist** mtp, int x);

//头插
void STL_push_head(struct STLlist** mtp, int x);

//尾删
void STL_pop_end(struct STLlist** mtp);

//头删
void STL_pop_head(struct STLlist** mtp);

//查找
STL* STL_srearch(struct STLlist* mtp, int x);

//在后面插入
void STL_insertaft(struct STLlist** mtp, int x);

//在后面销毁
void STL_eraseaft(struct STLlist** mtp);

//销毁单向链表
void STL_destroy(struct STLlist** mtp);