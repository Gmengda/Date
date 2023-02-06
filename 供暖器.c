#include <stdio.h>
#include <stdlib.h>

int cor(const void* a , const void* b)
{
    return *(int*)a - *(int*)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    qsort(houses,housesSize,sizeof(int),cor);
    qsort(heaters,heatersSize,sizeof(int),cor);
    int z[300000] = {0};
    int p = 0;
    int m;
    for(int i = 0 ; i < housesSize ; i++)
    {
        m = 10000000000;
        for(int j = 0 ; j < heatersSize ; j++)
        {
            int c = houses[i] - heaters[j];
            if(-c > 0 && -c < m)
            {
                m = -c;
            }
            else if(c > 0 && c < m)
            {
                m = c;
            }
            else if(c == 0)
            {
                m = 0;
            }
        }
        z[p++] = m;
    }
    qsort(z,p,sizeof(int),cor);
    return z[p - 1];
}
int main()
{
    int m[] = {1,2,3};
    int n[] = {2};
    findRadius(m,3,n,1);

    return 0;
}