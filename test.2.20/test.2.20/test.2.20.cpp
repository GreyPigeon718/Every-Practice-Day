//> 找出星型图的中心节点
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> degrees(n + 1);
        //> 将这些节点连线，计算出它的度。
        for (auto& edge : edges)
        {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        //> 度为n-1 的就为 中心节点
        for (int i = 1; ; ++i)
        {
            if (degrees[i] == n - 1)
            {
                return i;
            }
        }
    }
};

//> 填充每个节点的下一个右侧节点指针 II
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
        //> cur表示每一层的链表
        Node* cur = root;
        while (cur != NULL)
        {
            //> 遍历当前层的时候，为了方便操作在下一
            //> 层前面添加一个哑结点（注意这里是访问
            //> 当前层的节点，然后把下一层的节点串起来）
            Node* dummy = new Node(0);
            //> pre表示下一层的上一个节点
            Node* pre = dummy;
            while (cur != NULL)
            {
                if (cur->left != NULL)
                {
                    //如果当前节点的左子节点不为空，就让pre节点
                    //的next指向他，也就是把它串起来
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
            //把下一层串联成一个链表之后，让他赋值给cur，
            //后续继续循环，直到cur为空为止
            cur = dummy->next;
        }
        return root;
    }
};

//> 另一颗的子树
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

//> 1比特与2比特字符
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