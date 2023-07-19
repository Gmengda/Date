class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.size() - 1;
        string::iterator it = s.begin();
        string::iterator ti = s.end();
        int c = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == ' ')
            {
                reverse(it + i - c, it + i);
                c = 0;
                continue;
            }
            else if(i == n - 1)
            {
                reverse(it + i - c, ti);
            }
            c++;
        }
        return s;
    }
};