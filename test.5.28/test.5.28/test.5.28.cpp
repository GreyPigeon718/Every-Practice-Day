//> É¾³ý×îÍâ²ãµÄÀ¨ºÅ
// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         string res;
//         int num = 0;
//         for (char c : s)
//         {
//             if (c == ')')
//                 --num;
//             if (num)
//                 res.push_back(c);
//             if (c == '(')
//                 ++num;
//         }
//         return res;
//     }
// };
class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> sk;
        string res = "";
        for (char c : s)
        {
            if (c == ')')
                sk.pop();
            if (!sk.empty())
                res.push_back(c);
            if (c == '(')
                sk.emplace(c);
        }
        return res;
    }
};