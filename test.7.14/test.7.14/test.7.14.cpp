//> 0～n-1中缺失的数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i)
                return i;
        }
        return nums.size();
    }
};
class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() + 1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n - 1;
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
    void innoder(TreeNode* root)
    {
        if (root == NULL)
            return;
        innoder(root->left);
        nums.emplace_back(root->val);
        innoder(root->right);
    }
    int kthLargest(TreeNode* root, int k) {
        innoder(root);
        return nums[nums.size() - k];
    }
private:
    vector<int> nums;
};


//> 二叉搜索树的第k大节点
class Solution {
public:
    // 中序遍历逆序就是降序
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


//> 二叉树的深度
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> qe;
        qe.push(root);
        int ans = 0;
        while (!qe.empty())
        {
            int n = qe.size();
            while (n > 0)
            {
                TreeNode* node = qe.front();
                qe.pop();
                if (node->left)
                    qe.push(node->left);
                if (node->right)
                    qe.push(node->right);
                --n;
            }
            ans++;
        }
        return ans;
    }
};



//> 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return DeBal(root) >= 0;
    }
private:
    int DeBal(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftHeight = DeBal(root->left);
        int rightHeight = DeBal(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;
        else
            return max(leftHeight, rightHeight) + 1;
    }
};


//> 数组中数字出现的次数
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
            ans ^= nums[i];
        int pos = 1;
        while ((ans & pos) == 0)
            pos <<= 1;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pos & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        return { a, b };
    }
};



//> 数组中数字出现的次数 II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 1) {
            return nums[0];
        }
        for (int i = 0; i < nums.size() - 3; i += 3) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return nums[nums.size() - 1];
    }
};
