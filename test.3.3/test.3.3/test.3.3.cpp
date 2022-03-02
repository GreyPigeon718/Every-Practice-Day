//> 单词拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //> 背包容量
        for (int i = 1; i <= s.size(); ++i)
        {
            //> 背包物品
            for (int j = 0; j < i; ++j)
            {
                //> 字符串截取
                string s1 = s.substr(j, i - j);
                //> 当st找到对赢单词
                if (st.find(s1) != st.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};


//>  最长递增子序列
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
                //> 状态方程九尾 dp[i] = max (dp[j + 1],dp[i]);
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//>  最长递增子序列的个数
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //> 300题一样,不过需要两个数组
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int Max_Count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }

        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dp[i] == *max_element(dp.begin(), dp.end()))
                res += count[i];
        }
        return res;
    }
};
