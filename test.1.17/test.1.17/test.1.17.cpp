// 删除字符串中的所有相邻重复项

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> s1;
        string res;
        for (int i = 0; i < s.length(); ++i)
        {
            if (!s1.empty() && s[i] == s1.top())
                s1.pop();
            else
                s1.push(s[i]);
        }
        while (!s1.empty())
        {
            res.push_back(s1.top());
            s1.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};