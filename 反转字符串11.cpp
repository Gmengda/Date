class Solution {
public:
    string reverseStr(string s, int k) {

        int n = s.size();
        string::iterator it = s.begin();
        string::iterator ti = s.end();
        for(int i = 0 ; i < n / (2 * k) ; i++)
        {
            reverse(it + i * 2 * k, it + i * 2 * k + k);
        }

        int p = n % (2*k);
        if(p < k)
        {
            reverse(ti - p, ti);
        }
        else
        {
            reverse(ti - p, ti - p + k);
        }
        return s;
    }
};