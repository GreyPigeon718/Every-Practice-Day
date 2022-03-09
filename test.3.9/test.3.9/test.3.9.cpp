//> 最长回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int right = 0, left = 0;
        int tmp = INT_MIN;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                if (s[i] == s[j])
                {
                    //> 三种情况，相等相邻和不相邻
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
                if (j - i + 1 > tmp && dp[i][j])
                {
                    left = i;
                    right = j;
                    tmp = j - i + 1;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};
//> 牛顿迭代法 sqrt
class Solution {
    int s;

    public int mySqrt(int x) {
        s = x;
        if (x == 0) return 0;
        return ((int)(sqrts(x)));
    }

    public double sqrts(double x) {
        double res = (x + s / x) / 2;
        if (res == x) {
            return x;
        }
        else {
            return sqrts(res);
        }
    }
}
