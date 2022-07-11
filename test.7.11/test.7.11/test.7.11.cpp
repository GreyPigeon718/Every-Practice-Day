
//> 把数字翻译成字符串
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        //> dp[i]: 前i个字符的翻译方法种类
        vector<int> dp(n + 1);
        dp[0] = 1;
        //> 从 左 -> 右
        for (int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i - 1];
            if (i > 1)
            {
                int num = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (num >= 10 && num <= 25)
                {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};

