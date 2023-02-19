#include<stdio.h>

double average(int* salary, int salarySize){
    int min = 1000000;
    int max = 1000;
    double sum = 0;

    for(int i = 0; i < salarySize; i++)
    {
        sum += salary[i];
        if(salary[i] < min)
        {
            min = salary[i];
        }
        if(salary[i] > max)
        {
            max = salary[i];
        }
    }
    return (sum - min - max) / (salarySize - 2);
}