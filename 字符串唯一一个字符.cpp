class Solution {
public:
    int firstUniqChar(string s) {
        int m[30] = {0};

        int n = s.size();
        for(int i = 0 ; i < n ; i++)
        {
            m[s[i] - 'a']++;
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(m[s[i] - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};