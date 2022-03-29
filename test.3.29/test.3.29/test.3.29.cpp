//> 跳跃游戏 III
class Solution {
public:
    bool DFS(vector<int>& arr, int start)
    {
        if (start < 0 || start >= n || arr[start] == -1)
            return false;
        int x = arr[start];
        if (x == 0)
            return true;
        arr[start] = -1;
        return DFS(arr, x + start) || DFS(arr, start - x);
    }
    bool canReach(vector<int>& arr, int start) {
        //> DFS
        n = arr.size();
        return DFS(arr, start);
    }
private:
    int n;
};


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0)
            return true;

        int n = arr.size();
        vector<bool> used(n, false);
        queue<int> q;
        q.push(start);
        used[start] = true;

        while (!q.empty())
        {
            int index = q.front();
            q.pop();
            //> 这次跳跃的位置并未跳过,向右跳
            if (arr[index] + index < n && !used[index + arr[index]])
            {
                if (arr[index + arr[index]] == 0) {
                    return true;
                }
                q.push(arr[index] + index);
                used[arr[index] + index] = true;
            }
            //> 向左跳
            if (index - arr[index] >= 0 && !used[index - arr[index]])
            {
                if (arr[index - arr[index]] == 0)
                    return true;
                q.push(index - arr[index]);
                used[index - arr[index]] = true;
            }
        }
        return false;
    }
};

//> 平衡二叉树
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
    int DepBal(TreeNode* Node)
    {
        if (Node == nullptr)
            return 0;
        int leftTree = DepBal(Node->left);
        int rightTree = DepBal(Node->right);
        if (leftTree == -1 || rightTree == -1 || abs(leftTree - rightTree) > 1)
            return -1;
        else
            return max(leftTree, rightTree) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return DepBal(root) >= 0;
    }
};

//> 二叉搜索树的第k大节点
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
    void dfs(TreeNode* root, int& k)
    {
        if (root == NULL)
            return;
        dfs(root->right, k);
        --k;
        if (!k)
            res = root->val;
        dfs(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
private:
    int res;
};