#define _CRT_SECURE_NO_WARNINGS 1
/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param numbers int����һά����
 * @param numbersLen int numbers���鳤��
 * @param target int����
 * @return int����һά����
 * @return int* returnSize ������������
 */
#include <math.h>
#include <stdlib.h>
int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    // write code here
    int* m = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersLen; i++)
    {
        if (numbers[i] > target)
        {
            continue;
        }
        for (int j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                if (i < j)
                {
                    m[0] = i + 1;
                    m[1] = j + 1;
                }
                else
                {
                    m[1] = i + 1;
                    m[0] = j + 1;
                }
                break;
            }
        }
    }
    *returnSize = 2;
    return  m;
}