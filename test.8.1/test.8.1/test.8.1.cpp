//> 二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL)
            return root;
        if (left != NULL && right == NULL)
            return left;
        else if (left == NULL && right != NULL)
            return right;
        else
            return NULL;

    }
};