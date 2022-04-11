//> 统计各位数字都不同的数字个数
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //> dp[i] : 整数i各位数字都不同的数字个数
        if (n == 0)
            return 1;
        vector<int> dp(n + 1);
        //> 初始化 dp[0] = 0; dp[1] = 10;
        dp[0] = 1;
        dp[1] = 10;
        //> 遍历方向 i == 2 -> i == n
        for (int i = 2; i <= n; ++i)
        {
            //> 状态转移方程：dp[i] = dp[i-1] + (dp[i-1] - dp[i-2]) * (10 - i + 1)
            //> 这里可以仔细想一想
            //> n == 1  0,1,2,3,......9    10
            //> n == 2  0,10,20,......98   10 + 9 * (10 - 2 + 1)
            //> n == 3  0,............987  10 + 9 * (10 - 2 + 1) * (10 - 3 + 1) 
            dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2]) * (10 - i + 1);
        }
        return dp[n];
    }
};

//>  不同的二叉搜索树
class Solution {
public:
    int numTrees(int n) {

        //> dp[i]:由i个节点组成的二叉搜索树种数
        vector<int> dp(n + 1);
        //> 初始化状态：dp[0] = 0(空也为二叉搜索树)dp[1] = 1;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            //> 递归方向 ： 从递归公式：dp[i] += dp[j - 1] * dp[i - j]
            //> 例子：dp[3] = 1为头节点的二叉树种树 + 2为头节点的二叉树种树 + 3为头节点的二叉树种树
            //>可以看出，
            //> 节点数为i的状态是依靠 i之前节点数的状态。
            //> 那么遍历i里面每一个数作为头结点的状态，用j来遍历。
        {
            for (int j = 1; j <= i; ++j)
            {
                //> dp[i] 状态转移方程：d[i] = dp[i - j] * dp[j - 1]
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        return dp[n];
    }
};