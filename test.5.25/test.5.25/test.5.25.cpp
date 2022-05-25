//> 剪绳子
class Solution {
public:
    int cuttingRope(int n) {
        //> dp[i]: 长度为i的绳子 剪完后最大乘积
        vector<int> dp(n + 1);
        //> 初始化：绳子最小为2  dp[2] = 1；
        dp[2] = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i - 1; ++j)
            {
                //> 状态转移方程
                //> 最小切成两段
                //> dp[i] = max(dp[i], max((i - j) * j, dp[i-j] * j))
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};


//> 剪绳子 II
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
            return n - 1;
        long k = n % 3;
        n /= 3;
        if (k == 1)
            return (int)(pow(3, n - 1) * 4 % 1000000007);
        else if (k == 2)
            return (int)(pow(3, n) * 2 % 1000000007);
        else
            return (int)(pow(3, n));
    }
private:
    long pow(long n, long m)
    {
        if (m == 0)
            return 1;
        long k = 1, x = n;
        while (m)
        {
            if (m & 1)
                k = (k * x) % 1000000007;
            m >>= 1;
            x = (x * x) % 1000000007;
        }
        return k;
    }
};



//> 数值的整数次方
class Solution {
public:
    double quickMul(double x, long long n) {
        if (n == 0)
            return 1;
        double res = 1.0;
        while (n > 0)
        {
            if (n & 1)
                res = res * x;
            n >>= 1;
            x *= x;
        }
        return res;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};