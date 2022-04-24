
//> 买卖股票的最佳时机含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //> dp[i][0] 表示第i天持有股票所省最多现金。 
        //> dp[i][1] 表示第i天不持有股票所得最多现金
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        //> 递推顺序 左->右
        for (int i = 1; i < prices.size(); ++i)
        {
            //> 状态转移方程：dp[i][0] = max(dp[i-1][0], dp[i - 1][1] + prices[i]);
        //> 状态转移方程：dp[i][1] = max(dp[i-1][1], dp[i - 1][0] + prices[i] - fee);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][0]);
    }
};


//> 最长递增子序列
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //> 每一个单独的字符都是递增子序列
        vector<int> dp(nums.size(), 1);
        int res = 0;

        //> 遍历顺序从前到后
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                //> dp[i] 表示i之前的最长递增序列长度
                //> 状态转移方程 dp[i] = max (dp[j]+1,dp[i]);
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//> 最长连续递增序列
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxlengrh = 0;
        while (right < nums.size())
        {
            if (right > 0 && nums[right] <= nums[right - 1])
            {
                left = right;
            }
            maxlengrh = max(right - left + 1, maxlengrh);
            right++;
        }
        return maxlengrh;
    }
};

