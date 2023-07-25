class Solution {
public:
    int trailingZeroes(int n) {
        int i= 0;
        while(n)
        {
            n /= 5;
            i += n;
        }
        return i;
    }
};