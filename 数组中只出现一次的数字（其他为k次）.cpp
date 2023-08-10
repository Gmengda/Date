class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param arr int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int foundOnceNumber(vector<int>& arr, int k) {
        int mm[32] = {0};
        for(int i = 0 ; i < arr.size() ; ++i)
        {
            int num = arr[i];
            for(int j = 0 ; j < 32 ; ++j)
            {
                mm[j] += num & 1;
                num >>= 1;
            }
        }
        int count = 0;
        for(int i = 0 ; i < 32 ; ++i)
        {
            count <<= 1;
            count |= mm[31 - i] % k;
        }

        return count;
    }
};