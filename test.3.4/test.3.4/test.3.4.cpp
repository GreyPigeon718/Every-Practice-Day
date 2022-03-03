//> �����ַ�����ɾ������
class Solution {
public:
    int minDistance(string word1, string word2) {
        //> dp[i][j] ��ʾ��i-1Ϊβ���ַ�����Ҫɾ���Ĵ���
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        //> ��ʼ����dp[i][0] = i, dp[0][j] = j;
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;
        //> ״̬���� ������� dp[i][j] = min (dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2)
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

//> ��Ǯ�һ�
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //> dp[i]��ʾ�ճɽ������ٸ��� ��׼���������������
        vector<int> dp(amount + 1, INT_MAX);
        //> ��ʼ��
        dp[0] = 0;
        //> ����˳���ȱ�����Ʒ���ٱ�������ǰ����
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                if (dp[j - coins[i]] != INT_MAX)
                {//> ״̬ת�Ʒ��� dp[j] = min(dp[j], dp[j - coin[i]])
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};

//> �������������������
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
        //> ˼·�ݹ飬���������һ����ͬһ�࣬��һ�ֲ���ͬһ��
        //> �������ϲ�ѯ
        if (root == p || root == q || root == NULL)
            return root;
        //������
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //> ����ͬһ��
        if (left != NULL && right != NULL)
            return root;
        //> ���Ҳ��ҵ�
        if (left == NULL && right != NULL)
            return right;
        //> ������ҵ�
        else if (left != NULL && right == NULL)
            return left;
        //> ������ڵ�
        else
            return NULL;

    }
};
