#include<map>
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n = str.size();
        if (n == 0)
            return -1;
        if (n == 1)
            return 0;
        for (int i = 0; i < n; i++){
            int flag = 0;
            for (int j = 0; j < n; j++){
                if (i != j && str[i] == str[j]){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                return i;
        }
        return -1;
    }
};