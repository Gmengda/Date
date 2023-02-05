#include <stdio.h>
#include <stdlib.h>
int cor(const void* a , const void* b)
{
    return *(int*)b - *(int*)a;
}

char ** findRelativeRanks(int* score, int scoreSize, int* returnSize){
    int s[10000] = {0};

    for(int i = 0 ; i < scoreSize ; i++)
    {
        s[i] = score[i];
    }
    int rank[5000] = {0};
    qsort(s,scoreSize,sizeof(int),cor);

    for(int i = 0 ; i < scoreSize ; i++)
    {
        for(int j = 0 ; j < scoreSize ; j++)
        {
            if(s[i] == score[j])
            {
                rank[j] = i + 1;
                break;
            }

        }
    }
    char** answer = (char**)malloc(sizeof(char*)*5002);
    for(int i = 0 ; i < 5002 ; i++)
    {
        answer[i] = (char*)calloc(11, sizeof(char));
    }
    

    for (int i = 0; i < scoreSize; i++) {

        if (rank[i] == 1) {
            answer[i] = "Gold Medal";
        }
        if (rank[i] == 2) {
            answer[i] = "Silver Medal";
        }
        if (rank[i] == 3) {
            answer[i] = "Bronze Medal";
        }
        if (rank[i] > 3) {
            sprintf(answer[i], "%d", rank[i]);
        }
    }
    *returnSize = scoreSize;
    return answer;
}
int main()
{
    int m[] = {1};
    findRelativeRanks(m,5);

    return 0;
}