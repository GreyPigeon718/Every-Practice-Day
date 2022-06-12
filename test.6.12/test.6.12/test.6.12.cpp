/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == NULL)
            return res;
        queue<TreeNode*> qe;
        qe.emplace(root);
        while (!qe.empty())
        {
            int size = qe.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = qe.front();
                qe.pop();
                res.emplace_back(node->val);
                if (node->left)
                    qe.push(node->left);
                if (node->right)
                    qe.push(node->right);
            }
        }
        return res;
    }
private:
    vector<int> res;
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return res;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty())
        {
            int size = qe.size();
            vector<int> path;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = qe.front();
                qe.pop();
                path.emplace_back(node->val);
                if (node->left)
                    qe.push(node->left);
                if (node->right)
                    qe.push(node->right);
            }
            res.emplace_back(path);
        }
        return res;
    }
private:
    vector<vector<int>> res;
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return res;
        queue<TreeNode*> qe;
        qe.push(root);
        int level = -1;
        while (!qe.empty())
        {
            int size = qe.size();
            vector<int> path;
            ++level;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = qe.front();
                qe.pop();
                path.emplace_back(node->val);
                if (node->left)
                    qe.push(node->left);
                if (node->right)
                    qe.push(node->right);
            }
            if (level & 1)
                reverse(path.begin(), path.end());
            res.emplace_back(path);
        }
        return res;
    }
private:
    vector<vector<int>> res;
};