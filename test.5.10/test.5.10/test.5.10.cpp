//>  两个字符串的删除操作
class Solution {
public:
    int minDistance(string word1, string word2) {
        //> dp[i][j]：以i-1为结尾的字符串word1，和以j-1位结尾的字符串word2，想要达到相等，所需要删除元素的最少次数。
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //> 初始化 dp[i][0] = i; dp[0][j] = j;
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;

        //> 遍历顺序 先word1 -> word2 (都可)
        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                //> 状态转移方程：
                //>  相等时：dp[i][j] = dp[i-1][j-1]
                //> 不相等时：dp[i][j] = min(dp[i-1][j], dp[i][j-1])
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

//> 编辑距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};