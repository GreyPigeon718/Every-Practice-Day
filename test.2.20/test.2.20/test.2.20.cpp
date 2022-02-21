//> �ҳ�����ͼ�����Ľڵ�
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degrees(n + 1);
        //> ����Щ�ڵ����ߣ���������Ķȡ�
        for (auto& edge : edges)
        {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        //> ��Ϊn-1 �ľ�Ϊ ���Ľڵ�
        for (int i = 1; ; ++i)
        {
            if (degrees[i] == n - 1)
            {
                return i;
            }
        }
    }
};

//> ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        //> cur��ʾÿһ�������
        Node* cur = root;
        while (cur != NULL)
        {
            //> ������ǰ���ʱ��Ϊ�˷����������һ
            //> ��ǰ�����һ���ƽ�㣨ע�������Ƿ���
            //> ��ǰ��Ľڵ㣬Ȼ�����һ��Ľڵ㴮������
            Node* dummy = new Node(0);
            //> pre��ʾ��һ�����һ���ڵ�
            Node* pre = dummy;
            while (cur != NULL)
            {
                if (cur->left != NULL)
                {
                    //�����ǰ�ڵ�����ӽڵ㲻Ϊ�գ�����pre�ڵ�
                    //��nextָ������Ҳ���ǰ���������
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right != NULL)
                {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            //����һ�㴮����һ������֮��������ֵ��cur��
            //��������ѭ����ֱ��curΪ��Ϊֹ
            cur = dummy->next;
        }
        return root;
    }
};

//> ��һ�ŵ�����
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
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if (root == NULL && subRoot == NULL)
            return true;
        if ((root == NULL && subRoot != NULL) || (root != NULL && subRoot == NULL) || (root->val != subRoot->val))
            return false;
        return check(root->left, subRoot->left) && check(root->right, subRoot->right);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if (root == NULL)
            return false;
        return check(root, subRoot) || dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};

//> 1������2�����ַ�
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int i = 0; i < bits.size();)
        {
            if (bits[i] == 0)
            {
                i++;
                if (i == bits.size())
                    return true;
            }
            if (bits[i] == 1)
            {
                i += 2;
                if (i == bits.size())
                    return false;
            }
        }
        return false;
    }
};