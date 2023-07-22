class Solution {
public:
    int maxPower(string s) {
        int i = 1;
        int n = 1;
        if(s.size() == 1)
        {
            return 1;
        }
        for(int size = 0 ; size < s.size() - 1 ; size++)
        {
            if(s[size] == s[size + 1])
            {
                i++;
            }
            else
            {
                if(i > n)
                {
                    n = i;
                }
                i = 1;
            }
        }
        if(i > n)
        {
            return i;
        }
        return n;
    }
};