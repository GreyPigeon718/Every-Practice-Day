//��һά����ת��ɶ�ά����
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (original.size() != m * n)
            return res;
        res.resize(m);
        for (int i = 0; i < res.size(); ++i)
        {
            res[i].resize(n);
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                res[i][j] = original[i * n + j];
            }
        }
        return res;
    }
};
//������Ʊ�����ʱ��
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int mins = 999999;
        for (int price : prices)
        {
            res = max(res, price - mins);
            mins = min(mins, price);
        }
        return res;
    }
};
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
//�������ľ���β������
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        int count = 1;
        while (!que.empty())
        {
            count++;
            int size = que.size();
            vector<int> v;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* tmp = que.front();
                que.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                    que.push(tmp->left);
                if (tmp->right)
                    que.push(tmp->right);
            }
            if (count % 2 != 0)
                reverse(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};