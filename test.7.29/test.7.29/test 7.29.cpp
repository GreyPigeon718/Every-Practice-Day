//ɾ�������������ظ�Ԫ��
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* cur = head;
        while (cur->next != NULL)
        {
            if (cur->val == cur->next->val)
            {
                cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
//��ת����
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
    ListNode* reverseList(ListNode* head) {
        ListNode* ls = new ListNode(-1);
        ListNode* l = ls;
        stack<int> sta;
        while (head != NULL)
        {
            sta.push(head->val);
            head = head->next;
        }
        while (!sta.empty())
        {
            l->next = new ListNode(sta.top());
            sta.pop();
            l = l->next;
        }
        return ls->next;
    }
};