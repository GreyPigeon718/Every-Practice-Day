//> ˮ������
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> up;
        int res = INT_MIN;
        //> �������ڣ����Ĵ𰸾��ǻ������ڵĴ�С
        //> �󴰿�
        int left = 0;
        //> �Ҵ���
        int right = 0;
        while (right < fruits.size())
        {
            up[fruits[right++]]++;
            //��ˮ�������Ѿ�װ������
            while (up.size() > 2)
            {
                up[fruits[left]]--;
                //> �󴰿��ƶ�
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

//> ��������������С���Բ�
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

//>  �������������������
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


//> �����������������������
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


//> ��ͬ��������
class Solution {
public:
    int numDistinct(string s, string t) {
        //> dp[i][j] ����s�ַ�����i-1Ϊ��βƥ��t�ַ���j-1���ַ����ĸ���
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //> ״̬ת�Ʒ��̷�������� s-1��t-1��ͬ/����ͬ
        //> ��ͬһ���֣�dp[i][j] = dp[i-1][j-1]
        //> ������ͬ�ظ��ַ�:dp[i][j] = dp[i-1][j];
        //> ����ͬ��dp[i][j] = dp[i-1][j]; _____________ϸ�����
        //> dp��ʼ����sΪ��ʱ,�����������ò���t�ַ��������գ�
        //> ����s[0][j] = 0;
        //> tΪ��ʱ��sɾ��һ�ξ���ƥ��
        //> ����s[i][0] = 1;
        //> ��s��t��Ϊ��ʱ��Ӧ�û���1�Σ�s[0][0] = 1;
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