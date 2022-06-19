//> 二叉搜索树与双向链表
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
private:
    Node* pre, * head;
    void dfs(Node* cur) {
        if (cur == nullptr) return;
        dfs(cur->left);
        if (pre != nullptr) pre->right = cur;
        else head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};
