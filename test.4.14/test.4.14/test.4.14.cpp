//> 最富有客户的资产总量
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_money = 0;
        for (int i = 0; i < accounts.size(); ++i)
        {
            int money_num = 0;
            for (int j = 0; j < accounts[0].size(); ++j)
            {
                money_num += accounts[i][j];
            }
            if (money_num > max_money)
                max_money = money_num;
        }
        return max_money;
    }
};
//> 零钱兑换 II
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //> 01背包
        //> dp[j] : 表示总金额为j的组合
        vector<int> dp(amount + 1, 0);

        //> dp[0] = 1;
        dp[0] = 1;

        //> 遍历顺序：先金额再硬币
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                //> 状态转移方程：dp[j] += dp[j - coins[i]];
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

//> 组合总和 Ⅳ
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //> 01背包
        //> dp[j]: 总和为j的组合个数
        vector<int> dp(target + 1, 0);

        //> 初始化： dp[0] = 1;
        dp[0] = 1;

        //> 遍历顺序：先背包在num
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                //> C++测试用例有两个数相加超过int的数据，所以需要在if里加上dp[i] < INT_MAX - dp[i - num]。
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                {
                    //> 状态转移方程：dp[i] += dp[i - nums[j]]
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
