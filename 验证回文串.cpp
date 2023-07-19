class Solution {
public:
    bool isPalindrome(string s) {

        int size = s.size() - 1;
        int i = 0, j = size;
        while(i < j)
        {
            while(!isalnum(s[i]) && i < j)
            {
                i++;
            }
            while(!isalnum(s[j]) && i < j)
            {
                j--;
            }
            cout << s[i] << " " << s[j];
            if(i < j)
            {
                if(tolower(s[i]) != tolower(s[j]))
                {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};