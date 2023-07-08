class Solution {
public:
string reverseWords(string s)
{
    // [start, pos)标记一个单词
    int start = 0;
    int pos = 0;
    while (start < s.size())
    {
        // 从start位置开始，从前往后找最近的一个空格
        pos = s.find(' ', start);
        // 如果pos是-1，说明[start, s.size())刚好是最后一个单词，调整下pos
        if (pos == -1)
            pos = s.size();
        // 逆置[start, pos)表示的单词
        std::reverse(s.begin()+start, s.begin() + pos);
        // 将start挪动到下一个单词的起始位置
        start = pos + 1;
    }
    return s;
    }
};