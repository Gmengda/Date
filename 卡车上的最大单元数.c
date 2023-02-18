#include<stdio.h>

int cor(const void* a,const void* b)
{
    return (*(int**)b)[1] - (*(int**)a)[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){
    qsort(boxTypes,boxTypesSize,sizeof(int*),cor);

    int m = 0;
    int i = 0;
    while(truckSize)
    {
        if(boxTypes[i][0] != 0)
        {
            m += boxTypes[i][1];
            boxTypes[i][0]--;
            truckSize--;
        }
        else if(i == boxTypesSize - 1)
        {
            break;
        }
        else
        {
            i++;
        }
        
        
    }
    return m;
}