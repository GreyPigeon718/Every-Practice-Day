//> 把数组排成最小的数
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        string res = "";
        for (auto num : nums)
        {
            str.emplace_back(to_string(num));
        }
        sort(str.begin(), str.end(), [](string& a, string& b)
            {
                return a + b < b + a;
            });
        for (int i = 0; i < str.size(); ++i)
            res += str[i];
        return res;
    }
};


//> 判断子序列
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty())
            return true;
        if (s.empty() || t.empty())
            return false;
        vector<bool> dp(s.size(), false);
        for (int i = 0, j = 0; i < t.size(); ++i)
        {
            if (s[j] == t[i])
            {
                dp[j] = true;
                ++j;
            }
        }
        return dp[s.size() - 1];
    }
};