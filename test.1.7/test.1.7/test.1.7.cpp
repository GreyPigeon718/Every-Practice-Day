// ·´×ªÁ´±í II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* rightNode = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            pre = pre->next;
        }
        for (int i = 0; i < right; ++i)
        {
            rightNode = rightNode->next;
        }
        ListNode* leftNode = pre->next;
        ListNode* suc = rightNode->next;
        pre->next = NULL;
        rightNode->next = NULL;
        Reverse(leftNode);
        pre->next = rightNode;
        leftNode->next = suc;
        return dummy->next;
    }
private:
    void Reverse(ListNode* node)
    {
        if (node == nullptr)
            return;
        ListNode* cur = node;
        ListNode* pre = NULL;
        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
    }
};