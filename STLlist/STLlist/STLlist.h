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

//��ӡ��������
void STLlistPrint(struct STLlist* mtp);

//β��
void STL_push_end(struct STLlist** mtp, int x);

//ͷ��
void STL_push_head(struct STLlist** mtp, int x);

//βɾ
void STL_pop_end(struct STLlist** mtp);

//ͷɾ
void STL_pop_head(struct STLlist** mtp);

//����
STL* STL_srearch(struct STLlist* mtp, int x);

//�ں������
void STL_insertaft(struct STLlist** mtp, int x);

//�ں�������
void STL_eraseaft(struct STLlist** mtp);

//���ٵ�������
void STL_destroy(struct STLlist** mtp);