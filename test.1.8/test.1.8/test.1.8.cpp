//二叉树的最近公共祖先
class Solution {
public:
    TreeNode* ans;
    bool Dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL)
            return false;
        bool lson = Dfs(root->left, p, q);
        bool rson = Dfs(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
        {
            ans = root;
        }
        return lson || rson || (root->val == p->val || root->val == q->val);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Dfs(root, p, q);
        return ans;
    }
};

//二叉搜索树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            }
            else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            }
            else {
                break;
            }
        }
        return ancestor;
    }
};
