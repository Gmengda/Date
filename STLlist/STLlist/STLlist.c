#define _CRT_SECURE_NO_WARNINGS 1
#include "STLlist.h"

STL* STLnewnode(int x)
{
    STL* m = (STL*)malloc(sizeof(STL));
    if (m == NULL)
    {
        perror("STL_push_end malloc");
    }
    m->m = x;
    m->point = NULL;
    return m;
}

void STLlistPrint(STL* mtp)
{
    while (mtp)
    {
        printf("%d->", mtp->m);
        mtp = mtp->point;
    }
    printf("NULL\n");
}

void STL_push_end(struct STLlist** mtp, int x)
{
    STL* m = STLnewnode(x);
    STL* POINT = *mtp;
    if (*mtp == NULL)
    {
        *mtp = m;
    }
    else
    {
        while (POINT->point != NULL)
        {
            POINT = POINT->point;
        }
        POINT->point = m;
    }
}

void STL_push_head(struct STLlist** mtp, int x)
{
    STL* m = STLnewnode(x);
    if (*mtp == NULL)
    {
        *mtp = m;
    }
    else
    {
        STL* cor = *mtp;
        m->point = cor;
        *mtp = m;
    }
}

void STL_pop_end(struct STLlist** mtp)
{
    assert(mtp);

    if ((*mtp)->point == NULL)
    {
        *mtp = NULL;
    }
    else
    {
        STL* m = *mtp;
        while (m->point->point != NULL)
        {
            m = m->point;
        }
        free(m->point);
        m->point = NULL;
    }
}

void STL_pop_head(struct STLlist** mtp)
{
    assert(mtp);

    STL* m = *mtp;
    *mtp = m->point;
    free(m);

}

STL* STL_srearch(struct STLlist* mtp, int x)
{
    assert(mtp);
    
    while (mtp)
    {
        if (mtp->m == x)
        {
            return mtp;
        }
        mtp = mtp->point;
    }
}

//在后面插入
void STL_insertaft(struct STLlist** mtp, int x)
{
    STL* m = STLnewnode(x);
    STL* point = *mtp;
    m->point = point->point;
    point->point = m;
}

void STL_eraseaft(struct STLlist** mtp)
{
    assert(mtp);
    STL* point = (*mtp)->point;
    (*mtp)->point = point->point;
    free(point);
    point->point = NULL;
}

void STL_destroy(struct STLlist** mtp)
{
    assert(mtp);
    STL* point = *mtp;
    while (point->point != NULL)
    {
        STL* s = point->point;
        point->point = s->point;
        free(s);
        s->point = NULL;
    }
    free(point);
    *mtp = NULL;
}