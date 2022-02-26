//> 不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        //> 首先它只能向左和向下移动
        //> 状态方程 dp[i][j] = dp[i-1][j] + dp[i][j-1]
        //> 初始化 在第i行和第j列只有一条路径
        //> dp[i][0] = 1 , dp[0][j] = 1;
        //> 边界就是m，n；
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //> 初始化完毕
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        //> 最后
        return dp[m - 1][n - 1];
    }
};

//> 最长回文字串
class Solution {
public:
    string longestPalindrome(string s) {
        //> dp[i][j] 表示的是[i,j]是否为回文串
        //> 当dp[i][j]为回文串时，dp[i+1][j-1]也是回文串
        //> "abba"->"bb"
        //> 状态方程就是 dp[i][j] = dp[i+1][j-1]
        //> 初始化 单个字符一定是最小的回文字串
        //> dp[i] = false;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxlen = 0;
        int left;
        int right;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                //> 分两种情况，相等和不相等
                if (s[i] == s[j])
                {
                    //> 相等分三种情况1.i和j相等2.i和j相邻3.i和j不相邻
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }

                if (j - i + 1 > maxlen && dp[i][j])
                {
                    maxlen = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

//> 等差数列划分
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0, cnt = 1;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                ans += cnt++;
            else
                cnt = 1;
        }
        return ans;
    }
};

//> 增量元素之间的最大差值
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int element = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > element)
                res = max(nums[i] - element, res);
            else
                element = nums[i];
        }
        return res;
    }
};