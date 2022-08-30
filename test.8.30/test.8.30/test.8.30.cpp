// 最短无序连续子数组
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;

        for (int i = 0; i < n; ++i)
        {
            // 从前到后，找到小于最大值的最后一个位置
            if (maxn > nums[i])
            {
                right = i;
            }
            else
            {
                maxn = nums[i];
            }
            // 从后到前，找到大于最小值的第一个位置
            if (minn < nums[n - i - 1])
            {
                left = n - i - 1;
            }
            else
            {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

// 和为 K 的子数组
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和，前缀和出现的次数
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int& x : nums)
        {
            pre += x;
            if (mp.count(pre - x))
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};


// 二叉树的直径
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // 二叉树的最长路径，一定在一颗树上! 且这条路径一定通过这颗树的root节点。"最长直径 = 这颗树左右子树的深度之和"
    // 这颗树可能是任一一颗子树，因此利用递归特性，从最底层子树找起 (函数返回值为深度，函数体中比较每一颗子树的直径，从而找到最长直径)
public:
    int maxLen = 0;
    int dfs(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        maxLen = max(left + right, maxLen);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};



