//> 后继者
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> sk;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur != nullptr || !sk.empty())
        {
            while (cur != nullptr)
            {
                sk.emplace(cur);
                cur = cur->left;
            }

            cur = sk.top();
            sk.pop();

            if (prev == p)
                return cur;
            prev = cur;
            cur = cur->right;
        }
        return nullptr;
    }
};

//> 旋转列表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)    return head;
        vector<int> vals;
        ListNode* p = head;
        int n = 0;
        while (p != NULL) {
            ++n;
            vals.emplace_back(p->val);
            p = p->next;
        }
        k = k % n;      //计算出实际有效移动的位置
        reverse(vals.begin(), vals.begin() + n - k);
        reverse(vals.begin() + n - k, vals.end());
        reverse(vals.begin(), vals.end());
        p = head;
        for (int i = 0; i < vals.size(); ++i) {
            p->val = vals[i];
            p = p->next;
        }
        return head;
    }
};
