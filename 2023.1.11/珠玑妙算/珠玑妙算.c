#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* masterMind(char* solution, char* guess, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    int n[4] = { 0 };
    answer[0] = 0;
    answer[1] = 0;
    for (int i = 0; i < 4; i++)
    {
        if (solution[i] == guess[i])
        {
            answer[0]++;
        }
        switch (solution[i])
        {
        case 'R':n[0]++; break;
        case 'G':n[1]++; break;
        case 'B':n[2]++; break;
        case 'Y':n[3]++; break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        switch (guess[i])
        {
        case 'R':if (n[0] != 0) { answer[1]++; n[0]--; }break;
        case 'G':if (n[1] != 0) { answer[1]++; n[1]--; }break;
        case 'B':if (n[2] != 0) { answer[1]++; n[2]--; }break;
        case 'Y':if (n[3] != 0) { answer[1]++; n[3]--; }break;
        }
    }
    answer[1] = answer[1] - answer[0];
    *returnSize = 2;
    return answer;
}