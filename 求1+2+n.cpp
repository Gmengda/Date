
#include <limits>
class num
{
public:
    num()
    {
        ++i;sum += i;
    }
    void init()
    {
        i = 0;sum = 0;
    }
    static int get()
    {
        return sum;
    }

private:
    static int i;
    static int sum;
};
int num::i = 0;
int num::sum = 0;
class Solution {
public:

    int Sum_Solution(int n) {
        num *s = new num[n];
        return num::get();
    }
};