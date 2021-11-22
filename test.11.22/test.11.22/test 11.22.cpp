//最长无重复子数组
// class Solution {
public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr)
    {
        unordered_map<int, int >mp;
        // 双指针
        int left = 0;
        int right = 0;
        int ret = 1;
        while (right < arr.size())
        {
            // 向右扩展
            if (mp[arr[right]] == 0)
            {
                mp[arr[right]] = right + 1;
                ret = max(ret, right - left + 1);
            }
            // 向左收缩
            else
            {
                while (left < mp[arr[right]])
                {
                    mp[arr[left]] = 0;
                    left++;
                }
                mp[arr[right]] = right + 1;
            }
            right++;
        }
        return ret;
    }
};
//重建二叉树
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* RulerTree(vector<int>pre, int left1, int right1, vector<int> vin, int left2, int right2)
    {
        // 当前部分的root
        TreeNode* root = new TreeNode(pre[left1]);
        int x = left2;
        while (pre[left1] != vin[x])
            x++;
        int left = x - left2; // 当前部分的左子树
        int right = right2 - x;// 当前部分的右子树
        if (left > 0)
            // 左子树 （left+1：下一个子树的根节点，right1:前序尾节点，left2:中序根节点之前是左子树， x-1：子树的左子树尾下表）
            root->left = RulerTree(pre, left1 + 1, left1 + left, vin, left2, x - 1);
        if (right > 0)
            root->right = RulerTree(pre, left1 + left + 1, right1, vin, x + 1, right2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        return RulerTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};
//删除链表的节点
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @param val int整型
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        // write code here
        if (val == head->val)
            return head->next;
        ListNode* tmp = head;
        while (tmp->next)
        {
            if (tmp->next->val == val)
            {
                tmp->next = tmp->next->next;
                return head;
            }
            tmp = tmp->next;
        }
        return head;
    }
};