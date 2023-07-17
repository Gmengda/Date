class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string num;
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int nn1, nn2;
        int carry = 0;
        int tmp = 0;

        while(n1 >= 0 || n2 >= 0)
        {
            nn1 = n1 < 0 ? 0 : num1[n1] - '0';
            nn2 = n2 < 0 ? 0 : num2[n2] - '0';
            tmp = nn1 + nn2 + carry;
            carry = tmp / 10;
            tmp %= 10;
            num += '0' + tmp;
            n1--;
            n2--;
        }
        if(carry != 0)
        {
            num += '1';
        }
        
        reverse(num.begin(),num.end());

        return num;
    }
};