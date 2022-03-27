//> 摆动序列
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //> 当前峰值
        int curdis = 0;
        //> 上一次的峰值
        int predis = 0;
        int res = 1;
        //>  2 2 5这种相同数值
        for (int i = 1; i < nums.size(); ++i)
        {
            curdis = nums[i] - nums[i - 1];
            //> 峰值的差异号
            if ((predis >= 0 && curdis < 0) || (predis <= 0 && curdis > 0))
            {
                res++;
                predis = curdis;
            }
        }
        return res;
    }
};

//>  dp解法
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return 1;
        //> dp[i][0]: 表示第i个数作为山峰的最长摆动序列
        //> dp[i][1]: 表示第i个数作为山谷的最长摆动序列
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        //> 初始化，dp[0][0] = dp[1][0] = 1
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;

            for (int j = 0; j < i; ++j)
            {
                //> 为山谷
                if (nums[j] > nums[i])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            for (int j = 0; j < i; ++j)
            {
                //> 为山谷
                if (nums[j] < nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};