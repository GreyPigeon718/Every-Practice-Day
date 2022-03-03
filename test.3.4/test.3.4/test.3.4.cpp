//> 两个字符串的删除操作
class Solution {
public:
    int minDistance(string word1, string word2) {
        //> dp[i][j] 表示以i-1为尾的字符串需要删除的次数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        //> 初始化，dp[i][0] = i, dp[0][j] = j;
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;
        //> 状态方程 三种情况 dp[i][j] = min (dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2)
        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1 });
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

//> 零钱兑换
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //> dp[i]表示凑成金额的最少个数 标准背包问题滚动数组
        vector<int> dp(amount + 1, INT_MAX);
        //> 初始化
        dp[0] = 0;
        //> 遍历顺序，先遍历物品，再背包，从前往后
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                if (dp[j - coins[i]] != INT_MAX)
                {//> 状态转移方程 dp[j] = min(dp[j], dp[j - coin[i]])
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};

//> 二叉树的最近公共祖先
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
