class Solution {
public:
    void reverseString(vector<char>& s) {

        int size = s.size() - 1;

        for(int i = 0 ; i < size; i++, size--)
        {
            swap(s[i],s[size]);
        }
    }
};