#define _CRT_SECURE_NO_WARNINGS 1

long mySqrt(long x)
{
    long target = 1;
    while (target * target <= x)
    {
        target++;
    }
    return target - 1;
}