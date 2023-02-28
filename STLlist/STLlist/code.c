#define _CRT_SECURE_NO_WARNINGS 1
#include "STLlist.h"

int main()
{
    STL* m = NULL;
    /*STL_push_end(&m, 1);
    STL_push_end(&m, 2);
    STL_push_end(&m, 3);
    STL_push_end(&m, 4);
    STLlistPrint(m);*/

    STL_push_head(&m, 1);
    STL_push_head(&m, 2);
    STL_push_head(&m, 3);
    STL_push_head(&m, 4);
    STLlistPrint(m);
    /*STL_pop_end(&m);
    STLlistPrint(m);
    STL_pop_end(&m);
    STLlistPrint(m);
 a0   STL_pop_end(&m);
    STLlistPrint(m);
    STL_pop_end(&m);
    STLlistPrint(m);*/
    
    /*printf("%d\n", STL_srearch(m,3)->m);
    STLlistPrint(m);*/


    STL* point = m;
    point = m->point;
    STL_insertaft(&point, 5);
    STLlistPrint(m);
    STL_eraseaft(&point);
    STLlistPrint(m);

    STL_destroy(&m);
    STLlistPrint(m);

    return 0;
}