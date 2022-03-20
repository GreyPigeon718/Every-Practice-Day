//> 最大的二叉树
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
    TreeNode* maxTree(vector<int>& nums)
    {
        //> 创建二叉树节点用来返回
        TreeNode* Node = new TreeNode(0);
        //> 递归的判出条件数组为一时结束
        if (nums.size() == 1)
        {
            Node->val = nums[0];
            return Node;
        }

        int max = -1; //> 题目中最小为0
        int index;
        //> 保存该数组的下标和值
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > max)
            {
                max = nums[i];
                index = i;
            }
        }
        Node->val = max;
        if (index > 0)
        {
            vector<int> LeftTree(nums.begin(), nums.begin() + index);
            Node->left = maxTree(LeftTree);
        }

        if (index < nums.size() - 1)
        {
            vector<int> RightTree(nums.begin() + index + 1, nums.end());
            Node->right = maxTree(RightTree);
        }
        return Node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        return maxTree(nums);
    }
};

//> 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) {
        //> 二叉搜索树的特性
        //> 递归判出条件，找到val或当前Node为NULL
        if (root == NULL || root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        return root;
    }
};




//> 合并二叉树
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
    TreeNode* mergeTwo(TreeNode* Node1, TreeNode* Node2)
    {
        //> 前序遍历
        //> 递归判出条件，其中一个节点为空
        if (Node1 == NULL)
            return Node2;
        if (Node2 == NULL)
            return Node1;
        //> 单层递归逻辑，创建一个节点
        //>  两个+和
        TreeNode* res = new TreeNode(0);
        res->val = Node1->val + Node2->val;
        if (Node1->left || Node2->left)
        {
            res->left = mergeTrees(Node1->left, Node2->left);
        }
        if (Node1->right || Node2->right)
        {
            res->right = mergeTrees(Node1->right, Node2->right);
        }
        return res;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeTwo(root1, root2);
    }
};