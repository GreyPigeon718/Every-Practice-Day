/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//> ª∑–Œ¡¥±Ì
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> umt;
        while (head)
        {
            if (umt.count(head) == 1)
                return true;
            umt.insert(head);
            head = head->next;
        }
        return false;
    }
};