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
    int getHeight(TreeNode* Node)
    {
        if (Node == NULL)
            return 0;
        int leftHeight = getHeight(Node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(Node->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return getHeight(root) == -1 ? false : true;
    }
};

//> 二叉树的所有路径 
/*Definition for a binary tree node.
* struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    *TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    *
};
*/
class Solution {
public:
    void backstarck(TreeNode* Node)
    {
        path.push_back(Node->val); //> 根
        if (Node->left == NULL && Node->right == NULL)
        {
            string s;
            for (int i = 0; i < path.size() - 1; ++i)
            {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            res.push_back(s);
            return;
        }

        if (Node->left)
        {
            backstarck(Node->left); //> 左
            path.pop_back();
        }

        if (Node->right)
        {
            backstarck(Node->right); //> 右
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return res;
        backstarck(root);
        return res;
    }
private:
    vector<int> path;
    vector<string> res;
};

//> 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        int leftTree = sumOfLeftLeaves(root->left); //> 左
        int rightTree = sumOfLeftLeaves(root->right);//> 右
        int midNode = 0;    //> 中

        if (root->left != NULL && root->left->right == NULL && root->left->left == NULL)
            midNode = root->left->val;
        sum += midNode + leftTree + rightTree;
        return sum;
    }
};

//> 找树左下角的值
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
public://> 题目先最底层，再最左边
    void GetLeftValue(TreeNode* Node, int LeftDeth)
    {
        //> 递归判出条件，叶子节点
        if (Node->left == nullptr && Node->right == nullptr)
        {
            if (LeftDeth > maxDeth)
            {
                maxDeth = LeftDeth;
                LeftValue = Node->val;
            }
            return;
        }

        if (Node->left)  //左
        {
            LeftDeth++;
            GetLeftValue(Node->left, LeftDeth); //> 回溯
            LeftDeth--;
        }
        if (Node->right) //右
        {
            LeftDeth++;
            GetLeftValue(Node->right, LeftDeth); //> 回溯
            LeftDeth--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        GetLeftValue(root, 0);
        return LeftValue;
    }
private:
    int maxDeth = INT_MIN;
    int LeftValue;
};

//> 相交链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        while (a || b)
        {
            if (a == b)
                return a;
            a = a ? a->next : headB;
            b = b ? b->next : headA;

        }
        return NULL;
    }
};

//> 路径总和
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
    bool flashback(TreeNode* Node, int target)
    {
        if (Node->left == nullptr && Node->right == nullptr && target == 0)
            return true;
        if (Node->left == nullptr && Node->right == nullptr)
            return false;
        if (Node->left)
        {
            target -= Node->left->val;
            if (flashback(Node->left, target))
                return true;
            target += Node->left->val;
        }
        if (Node->right)
        {
            target -= Node->right->val;
            if (flashback(Node->right, target))
                return true;
            target += Node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return flashback(root, targetSum - root->val);
    }
};


//> 等差数列划分 II - 子序列
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        // dp[3][2] = 5 -> nums[3]结尾 公差为2 的 等差数列（长度大于2）的个数为 5
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - nums[j];
                dp[i][d] += dp[j][d] + 1;
                // dp[j][d] 联合上 dp[i] 表示了长度至少为3的等差数列
                res += dp[j][d];
            }
        }
        return res;
    }
};
