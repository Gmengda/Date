class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        char* mmm = new char[150]();

        for(int i = 0 ; i < jewels.size() ; i++)
        {
            mmm[jewels[i]]++;
        }
        for(int i = 0 ; i < stones.size() ; i++)
        {
            if(mmm[stones[i]] != 0)
            {
                count++;
            }
        }
        return count;
    }
};