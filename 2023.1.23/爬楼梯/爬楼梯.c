#define _CRT_SECURE_NO_WARNINGS 1

int climbStairs(int n) {
    int a = 0;
    int b = 1;
    int c = a + b;
    for (int i = 1; i < n; i++)
    {
        a = b;
        b = c;
        c = a + b;
    }
    return c;
}