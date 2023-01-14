#define _CRT_SECURE_NO_WARNINGS 1
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param numbers int整型一维数组
 * @param numbersLen int numbers数组长度
 * @param target int整型
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
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