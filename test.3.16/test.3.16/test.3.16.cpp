//> 寻找两个正序数组的中位数
class Solution {
public:
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
    * 这里的 "/" 表示整除
    * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
    * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
    * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
    * 这样 pivot 本身最大也只能是第 k-1 小的元素
    * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
    * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
    * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
    */

    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true)
        {
            if (index1 == m)
                return nums2[k + index2 - 1];
            if (index2 == n)
                return nums1[k + index1 - 1];
            if (k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length = nums1.size() + nums2.size();
        if (length % 2)
            return getKthElement(nums1, nums2, (length + 1) / 2);
        else
            return (getKthElement(nums1, nums2, length / 2) + getKthElement(nums1, nums2, length / 2 + 1)) / 2.0;
    }
};


//>  二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        if (root == NULL)
            return vv;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty())
        {
            int size = qe.size();
            vector<int> v;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* tmp = qe.front();
                qe.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                    qe.push(tmp->left);
                if (tmp->right)
                    qe.push(tmp->right);
            }
            vv.push_back(v);
        }
        return vv;
    }
};

//> 二叉树的最大深度
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
    int getMaxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return getMaxDepth(root);
    }
};

//> 二叉树的最小深度
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
    int GetMinDepth(TreeNode* root)
    {
        if (root == 0)
            return 0;
        int leftDeth = GetMinDepth(root->left);
        int rightDeth = GetMinDepth(root->right);
        if (root->left == NULL && root->right != NULL)
            return rightDeth + 1;
        if (root->right == NULL && root->left != NULL)
            return leftDeth + 1;
        return min(leftDeth, rightDeth) + 1;
    }
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return GetMinDepth(root);
    }
};

//>  完全二叉树的节点个数
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
    int GetNodes(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int leftTree = GetNodes(root->left);
        int rightTree = GetNodes(root->right);

        return leftTree + rightTree + 1;
    }
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        return GetNodes(root);
    }
};