//> 打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        //> dp[i]:i 包括 i以内的房间，可偷窃的最高金额
        vector<int> dp(nums.size() + 1, 0);
        //> 初始化 dp[0] = nums[i] dp[1] = max(nums[0], nums[1])
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        //> 遍历顺序 左->右
        for (int i = 2; i < nums.size(); ++i)
        {
            //> 状态转移方程：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
//> 打家劫舍 II
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int result1 = robRange(nums, 0, nums.size() - 2);
        int result2 = robRange(nums, 1, nums.size() - 1);

        return max(result1, result2);
        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        dp[1] = nums[1];

        for (int i = 2; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
    int robRange(vector<int>& nums, int start, int end)
    {
        if (start == end)
            return nums[start];
        //> dp[i]: i 包括 i以内的可偷最高金额
        vector<int> dp(nums.size(), 0);
        //> 初始化：dp[start] = nums[start] dp[start + 1] = nums[start + 1]
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        //> 遍历顺序 左 -> 右
        for (int i = start + 2; i <= end; ++i)
        {
            //> 状态转移方程：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};

//> 打家劫舍 III
class Solution {
public:
    int rob(TreeNode* root) {
        //> dp[i]:下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode* cur)
    {
        if (cur == nullptr)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //> 偷当前节点
        int val1 = cur->val + left[0] + right[0];
        //> 不偷当前节点
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { val2, val1 };
    }
};
