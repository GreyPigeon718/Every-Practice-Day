// 乘积最大子数组
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return nums[0];
        else if (nums.size() == 1)
            return nums[0];
        int Max = nums[0], Min = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int Max_cur = Max, Min_cur = Min;
            Max = max(Max_cur * nums[i], max(nums[i], Min_cur * nums[i]));
            Min = min(Max_cur * nums[i], min(nums[i], Min_cur * nums[i]));
            res = max(Max, res);
        }
        return res;
    }
};
//数组中数字出现的次数
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        vector<int> v(2, 0);
        for (int e : nums)
            res ^= e;
        int div = 1;
        while ((div & res) == 0)
            div <<= 1;
        for (int e : nums)
        {
            if (div & e)
                v[0] ^= e;
            else
                v[1] ^= e;
        }
        return v;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 树的子结构
class Solution {
public:
    bool isEqual(TreeNode* a, TreeNode* b)
    {
        if (b == nullptr)
            return true;
        if (a == nullptr || a->val != b->val)
            return false;
        return isEqual(a->left, b->left) && isEqual(a->right, b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return isEqual(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};



