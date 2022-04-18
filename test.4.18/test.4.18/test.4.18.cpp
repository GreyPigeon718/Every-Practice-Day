//> ��ҽ���
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        //> dp[i]:i ���� i���ڵķ��䣬��͵�Ե���߽��
        vector<int> dp(nums.size() + 1, 0);
        //> ��ʼ�� dp[0] = nums[i] dp[1] = max(nums[0], nums[1])
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        //> ����˳�� ��->��
        for (int i = 2; i < nums.size(); ++i)
        {
            //> ״̬ת�Ʒ��̣�dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
//> ��ҽ��� II
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
        //> dp[i]: i ���� i���ڵĿ�͵��߽��
        vector<int> dp(nums.size(), 0);
        //> ��ʼ����dp[start] = nums[start] dp[start + 1] = nums[start + 1]
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        //> ����˳�� �� -> ��
        for (int i = start + 2; i <= end; ++i)
        {
            //> ״̬ת�Ʒ��̣�dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }
};

//> ��ҽ��� III
class Solution {
public:
    int rob(TreeNode* root) {
        //> dp[i]:�±�Ϊ0��¼��͵�ýڵ����õ��ĵ�����Ǯ���±�Ϊ1��¼͵�ýڵ����õ��ĵ�����Ǯ��
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode* cur)
    {
        if (cur == nullptr)
            return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //> ͵��ǰ�ڵ�
        int val1 = cur->val + left[0] + right[0];
        //> ��͵��ǰ�ڵ�
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { val2, val1 };
    }
};
