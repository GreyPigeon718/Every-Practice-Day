//����ظ�������
// class Solution {
public:
    /**
     *
     * @param arr int����vector the array
     * @return int����
     */
    int maxLength(vector<int>& arr)
    {
        unordered_map<int, int >mp;
        // ˫ָ��
        int left = 0;
        int right = 0;
        int ret = 1;
        while (right < arr.size())
        {
            // ������չ
            if (mp[arr[right]] == 0)
            {
                mp[arr[right]] = right + 1;
                ret = max(ret, right - left + 1);
            }
            // ��������
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
//�ؽ�������
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
        // ��ǰ���ֵ�root
        TreeNode* root = new TreeNode(pre[left1]);
        int x = left2;
        while (pre[left1] != vin[x])
            x++;
        int left = x - left2; // ��ǰ���ֵ�������
        int right = right2 - x;// ��ǰ���ֵ�������
        if (left > 0)
            // ������ ��left+1����һ�������ĸ��ڵ㣬right1:ǰ��β�ڵ㣬left2:������ڵ�֮ǰ���������� x-1��������������β�±�
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
//ɾ������Ľڵ�
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
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @param val int����
     * @return ListNode��
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