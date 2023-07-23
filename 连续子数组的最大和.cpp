class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型
     */
    int FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int sum = array[0], temp = sum;
        for(int i = 1; i < array.size(); ++i)
        {
            if(sum < 0)
            {
                sum = array[i];
            }
            else
            {
                sum += array[i];
            }
            temp = temp > sum ? temp : sum;
          }
        return temp;
    }
};