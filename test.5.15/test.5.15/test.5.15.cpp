//> 正则表达式的匹配
class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size(), n = p.size();

        //> dp[i][j]表示：s前i个字符与p的前j个字符是否匹配
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        //> 初始化：dp[0][0] = true;
        dp[0][0] = true;

        //> s一个字符都不选，此时要考虑p包含*的情况，因为*可以不匹配
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        //> 遍历顺序：先s后p
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //> 状态转移方程:
                //> 当 p[j-1] != '*', dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
                //> 当 p[j-1] == '*',分两种情况：第一种匹配0次，也就是不匹配；第二种匹配n次（n=1,2,3,..）
                //> 第一种情况 dp[i][j] = dp[i][j-2];
                //> 第二种情况 dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.')
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};

//> 最大三角形面积
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //> 海伦公式：s = sqrt(p * (p - a) * (p - b) * (p - c));p = 1/2(a + b + c)
        double maxs = 0.0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int s = j + 1; s < n; s++) {
                    double a = sqrt(pow(abs(points[j][0] - points[i][0]), 2) + pow(abs(points[j][1] - points[i][1]), 2));
                    double b = sqrt(pow(abs(points[s][0] - points[j][0]), 2) + pow(abs(points[s][1] - points[j][1]), 2));
                    double c = sqrt(pow(abs(points[i][0] - points[s][0]), 2) + pow(abs(points[i][1] - points[s][1]), 2));
                    double l = (a + b + c) * 0.5;
                    maxs = max(maxs, sqrt(l * (l - a) * (l - b) * (l - c)));
                }
            }
        }
        return maxs;
    }
};
