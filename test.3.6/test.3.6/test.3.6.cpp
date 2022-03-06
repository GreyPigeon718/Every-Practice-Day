//> 最长特殊序列 Ⅰ

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a != b ? max(a.size(), b.size()) : -1;
    }
};