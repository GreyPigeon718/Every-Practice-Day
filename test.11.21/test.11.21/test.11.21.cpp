//重建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* RulerTree(vector<int> pre, int left1, int right1, vector<int> vin, int left2, int right2)
    {
        //  开辟当前根节点空间
        TreeNode* root = new TreeNode(pre[left1]);
        int x = left2;
        //. 找到当前根节点在中序遍历的位置
        while (pre[left1] != vin[x])
            x++;
        int left = x - left2;//左子树
        int right = right2 - x; //右子树
        if (left > 0)
            root->left = RulerTree(pre, left1 + 1, left1 + left, vin, left2, x - 1);
        if (right > 0)
            root->right = RulerTree(pre, left1 + left + 1, right1, vin, x + 1, right2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        return RulerTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};
//二叉搜索树的第k个节点
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param proot TreeNode类
     * @param k int整型
     * @return int整型
     */
    void preorder(vector<int>& v, TreeNode* proot)
    {
        if (proot == nullptr)
            return;
        v.push_back(proot->val);
        preorder(v, proot->left);
        preorder(v, proot->right);
    }
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (proot == nullptr)
            return -1;
        vector<int> v;
        preorder(v, proot);
        if (k < 1 || k > v.size())
            return -1;
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};// 按照之字形打印二叉树
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<vector<int>> vv;
        int count = -1; //满足第一次加为偶数
        while (!q.empty())
        {
            count++;
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode* Node = q.front();
                q.pop();
                v.push_back(Node->val);
                //层序遍历
                if (Node->left)
                    q.push(Node->left);
                if (Node->right)
                    q.push(Node->right);
            }
            if (count % 2)
                reverse(v.begin(), v.end());
            vv.push_back(v);
        }
        return vv;
    }
};
// 最长无重复数字串
class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_map<int, int > mp;
        int left = 0;
        int right = 0;
        int ret = 1;
        while (right < arr.size())
        {
            //   向右扩展map
            if (mp[arr[right]] == 0)
            {
                mp[arr[right]] = right + 1;
                ret = max(ret, right - left + 1);
            }
            //   向左收缩map
            else
            {
                while (left < mp[arr[right]])
                {
                    mp[arr[left]] = 0;
                    left++;
                }
                mp[arr[right]] = right + 1;
            }
            right++;
        }
        return ret;
    }
};
//在二叉树中找到两个节点的最近公共祖先
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode类
     * @param o1 int整型
     * @param o2 int整型
     * @return int整型
     */
    TreeNode* DFS(TreeNode* Node, int o1, int o2)
    {
        if (Node == nullptr)
            return nullptr;
        if (Node->val == o1 || Node->val == o2)
            return Node;
        TreeNode* left = DFS(Node->left, o1, o2);
        TreeNode* right = DFS(Node->right, o1, o2);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return Node;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        //TreeNode* grandNode = DFS(root, o1, o2);
        return DFS(root, o1, o2)->val;
    }
};
// 二分查找II
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型vector
     * @param target int整型
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right--;
            else if (nums[mid] < target)
                left++;
            else
            {
                while (mid != 0 && nums[mid] == nums[mid - 1])
                    mid--;
                return mid;
            }
        }
        return -1;
    }
};