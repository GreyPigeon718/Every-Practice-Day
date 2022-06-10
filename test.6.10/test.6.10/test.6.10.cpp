//> 数青蛙
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;

        int frog = 0;
        int res = INT_MIN;

        for (auto& ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                ++frog;
                c++;
            }
            else if (ch == 'r')
                ++r;
            else if (ch == 'o')
                ++o;
            else if (ch == 'a')
                ++a;
            else if (ch == 'k')
            {
                ++k;
                --frog;
            }
            res = max(res, frog);
            if (!(c >= r && r >= o && o >= a && a >= k))
                return -1;
        }
        if (c != r || r != o || o != a || a != k)
            return -1;
        return res;
    }
};


//> 树的子结构
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
    bool travesal(TreeNode* a, TreeNode* b)
    {
        if (b == nullptr)
            return true;
        if (a == nullptr && b != nullptr)
            return false;
        if (a != nullptr && a->val != b->val)
            return false;
        bool left = travesal(a->left, b->left);
        bool right = travesal(a->right, b->right);
        return left && right;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return travesal(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

//> 验证栈序列 //> 栈的压入、弹出序列
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sk;
        for (int i = 0, j = 0; i < pushed.size(); ++i)
        {
            sk.emplace(pushed[i]);
            while (!sk.empty() && sk.top() == popped[j])
            {
                ++j;
                sk.pop();
            }
        }
        return sk.empty();
    }
};