//> 从根到叶的二进制数之和
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
public:
    int res = 0;
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* root, int presum)
    {
        if (!root)
            return;
        presum = presum * 2 + root->val;
        if (!root->left && !root->right)
            res += presum;
        dfs(root->left, presum);
        dfs(root->right, presum);
    }
};