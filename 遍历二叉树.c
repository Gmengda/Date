#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char val;
    struct tree* left;
    struct tree* right;
}t;

void treeput(t* m)
{
    if(m == NULL)
    {
        return ;
    }
    treeput(m->left);
    printf("%c ",m->val);
    treeput(m->right);

}


t* treeord(char* cs,int* j)
{

    if(cs[*j] == '#')
    {
        return NULL;
    }
    t* m = (t*)malloc(sizeof(t));
    m->val = cs[*j];
    m->left = NULL;
    m->right = NULL;
    (*j)++;
    m->left = treeord(cs,j);
    (*j)++;
    m->right = treeord(cs,j);
    return m;
}

int main() {
    char cs[105];
    int i = 0;
    t* m = (t*)malloc(sizeof(t));
    m->left = NULL;
    m->right = NULL;
    scanf("%s",cs);
    m = treeord(cs,&i);
    treeput(m);

    return 0;
}