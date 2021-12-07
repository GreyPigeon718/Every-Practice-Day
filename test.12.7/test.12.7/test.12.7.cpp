// 重建二叉树
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
    TreeNode* rescue(vector<int>& preorder, int left1, int right1, vector<int>& inorder, int left2, int right2)
    {
        TreeNode* root = new TreeNode(preorder[left1]);
        int x = left2;
        while (preorder[left1] != inorder[x])
            x++;
        int left = x - left2; //当前左子树
        int right = right2 - x; //当前右子树
        if (left > 0)
            root->left = rescue(preorder, left1 + 1, left1 + left, inorder, left2, x - 1);
        if (right > 0)
            root->right = rescue(preorder, left1 + left + 1, right1, inorder, x + 1, right2);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;
        return rescue(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// 用栈实现队列
class MyQueue {
public:
    MyQueue() {}

    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st2.empty())
        {
            in2out();
        }
        int x = st2.top();
        st2.pop();
        return x;
    }

    int peek()
    {
        if (st2.empty())
            in2out();
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
    void in2out()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
};


/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
// 从上到下打印二叉树 III
class Solution {
public:
    vector<vector<int>> vv;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return vv;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v;
            count++;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            if (count % 2 == 0)
                reverse(v.begin(), v.end());
            vv.push_back(v);
        }
        return vv;
    }
};