//> 水果成篮
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> up;
        int res = INT_MIN;
        //> 滑动窗口，最后的答案就是滑动窗口的大小
        //> 左窗口
        int left = 0;
        //> 右窗口
        int right = 0;
        while (right < fruits.size())
        {
            up[fruits[right++]]++;
            //当水果种类已经装了两种
            while (up.size() > 2)
            {
                up[fruits[left]]--;
                //> 左窗口移动
                if (up[fruits[left]] == 0)
                {
                    up.erase(fruits[left]);
                }
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

//> 二叉搜索树的最小绝对差
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
    void traversal(TreeNode* Node)
    {
        if (Node == NULL)
            return;
        traversal(Node->left);
        if (pre != NULL)
            res = min(res, Node->val - pre->val);
        pre = Node;
        traversal(Node->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
private:
    int res = INT_MAX;
    TreeNode* pre;
};

//> 二叉搜索树中的众数
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
    void traversal(TreeNode* Node)
    {
        if (Node == NULL)
            return;
        traversal(Node->left);
        if (pre == NULL)
            count = 1;
        else if (pre->val == Node->val)
            count++;
        else
            count = 1;
        if (count == MaxCount)
            res.push_back(Node->val);
        if (count > MaxCount)
        {
            res.clear();
            MaxCount = count;
            res.push_back(Node->val);
        }
        pre = Node;
        traversal(Node->right);
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return res;
    }
private:
    TreeNode* pre;
    vector<int> res;
    int MaxCount = INT_MIN;
    int count = 0;
};

//>  二叉树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //> 思路递归，两种情况，一种再同一侧，另一种不在同一侧
        //> 从下往上查询
        if (root == p || root == q || root == NULL)
            return root;
        //左子树
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //> 不在同一侧
        if (left != NULL && right != NULL)
            return root;
        //> 在右侧找到
        if (left == NULL && right != NULL)
            return right;
        //> 在左测找到
        else if (left != NULL && right == NULL)
            return left;
        //> 无这个节点
        else
            return NULL;

    }
};


//> 二叉搜索树的最近公共祖先
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
    TreeNode* traversal(TreeNode* Node, TreeNode* p, TreeNode* q)
    {
        if (Node == NULL)
            return Node;

        if (Node->val > p->val && Node->val > q->val)
        {
            TreeNode* left = traversal(Node->left, p, q);
            if (left != NULL)
            {
                return left;
            }
        }

        if (Node->val < p->val && Node->val < q->val)
        {
            TreeNode* right = traversal(Node->right, p, q);
            if (right != NULL)
            {
                return right;
            }
        }
        return Node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traversal(root, p, q);
    }
};


//> 不同的子序列
class Solution {
public:
    int numDistinct(string s, string t) {
        //> dp[i][j] 代表s字符串以i-1为结尾匹配t字符串j-1的字符串的个数
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //> 状态转移方程分两种情况 s-1和t-1相同/不相同
        //> 相同一部分：dp[i][j] = dp[i-1][j-1]
        //> 连续相同重复字符:dp[i][j] = dp[i-1][j];
        //> 不相同：dp[i][j] = dp[i-1][j]; _____________细想感悟
        //> dp初始化：s为空时,无论怎样都得不到t字符串（不空）
        //> 所以s[0][j] = 0;
        //> t为空时，s删除一次就能匹配
        //> 所以s[i][0] = 1;
        //> 当s，t都为空时，应该还是1次，s[0][0] = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};