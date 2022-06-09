//> �������������
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
        if (root == nullptr)
            return {};
        queue<TreeNode*> qe;
        qe.push(root);
        vector<vector<int>> res;
        while (!qe.empty())
        {
            int size = qe.size();
            vector<int> v;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* Node = qe.front();
                qe.pop();
                v.push_back(Node->val);
                if (Node->left)
                    qe.push(Node->left);
                if (Node->right)
                    qe.push(Node->right);
            }
            res.push_back(v);
        }
        return res;
    }
};

//> �����������ĺ����������
class Solution {
public:
    bool traversal(vector<int>& postorder, int start, int end) {
        /* �ݹ���ֹ���� */
        if (start >= end) return true;
        int index = start;
        /* �м䴦���߼� */
        while (postorder[index] < postorder[end]) index++;
        /* ��¼�ָ�� */
        int midIndex = index;
        while (postorder[index] > postorder[end]) index++;
        /* �ݹ��������� */
        bool left = traversal(postorder, start, midIndex - 1);
        bool right = traversal(postorder, midIndex, end - 1);
        return index == end && left && right;
    }
    bool verifyPostorder(vector<int>& postorder) {
        return traversal(postorder, 0, postorder.size() - 1);
    }
};