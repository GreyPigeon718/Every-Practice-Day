//> ���Ķ�����
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
        //> �����������ڵ���������
        TreeNode* Node = new TreeNode(0);
        //> �ݹ���г���������Ϊһʱ����
        if (nums.size() == 1)
        {
            Node->val = nums[0];
            return Node;
        }

        int max = -1; //> ��Ŀ����СΪ0
        int index;
        //> �����������±��ֵ
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

//> �����������е�����
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
        //> ����������������
        //> �ݹ��г��������ҵ�val��ǰNodeΪNULL
        if (root == NULL || root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        if (root->val < val)
            return searchBST(root->right, val);
        return root;
    }
};




//> �ϲ�������
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
        //> ǰ�����
        //> �ݹ��г�����������һ���ڵ�Ϊ��
        if (Node1 == NULL)
            return Node2;
        if (Node2 == NULL)
            return Node1;
        //> ����ݹ��߼�������һ���ڵ�
        //>  ����+��
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