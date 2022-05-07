class Solution {
public:
    int numDistinct(string s, string t) {
        //> dp[i][j] 代表s字符串以i-1为结尾匹配t字符串j-1的字符串的个数
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //> 状态转移方程分两种情况 s-1和t-1相同/不相同
        //> 相同一部分：dp[i][j] = dp[i-1][j-1]
        //> 连续相同重复字符:dp[i][j] = dp[i-1][j];
        //> 不相同：dp[i][j] = dp[i-1][j]; _____________细想感悟
        //> dp初始化：s为空时,无论怎样都得不到t字符串（不空）
        //> 所以s[0][j] = 0;
        //> t为空时，s删除一次就能匹配
        //> 所以s[i][0] = 1;
        //> 当s，t都为空时，应该还是1次，s[0][0] = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};