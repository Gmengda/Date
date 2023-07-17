class Solution {
public:
    int StrToInt(string str) {
        
        int num = 0;
        int falg = 0;
        string::iterator it = str.begin(); 

        while(it != str.end())
        {
            if(*it < '0' || *it > '9')
            {
                if(*it == '-')
                {
                    falg = 1;
                    it++;
                    continue;
                }
                else if(*it == '+')
                {
                    it++;
                    continue;
                }
                return 0;
            }
            num *=10;
            num += *it - '0';
            it++;
        }
        if(falg)
        {
            num = -num;
        }
        return num;
    }
};