//合并k个有序链表
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
    ListNode* mergTwoLists(ListNode* a, ListNode* b)
    {
        if ((!a) || (!b))
            return a ? a : b;
        ListNode head, * tail = &head, * atr = a, * btr = b;
        while (atr && btr)
        {
            if (atr->val < btr->val)
            {
                tail->next = atr;
                atr = atr->next;
            }
            else
            {
                tail->next = btr;
                btr = btr->next;
            }
            tail = tail->next;
        }
        tail->next = (atr ? atr : btr);
        return head.next;
    }
    ListNode* merg(vector<ListNode*>& lists, int begin, int end)
    {
        if (begin == end)
            return lists[begin];
        if (begin > end)
            return nullptr;
        int mid = (begin + end) >> 1;
        return mergTwoLists(merg(lists, begin, mid), merg(lists, mid + 1, end));
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merg(lists, 0, lists.size() - 1);
    }
};
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
    ListNode* mergeTwoList(ListNode* a, ListNode* b)
    {
        if ((!a) || (!b)) //a,b有一个为空
            return a ? a : b;
        ListNode head, * tail = &head, * atr = a, * btr = b;
        while (atr && btr)
        {
            if (atr->val > btr->val)
            {
                tail->next = btr;
                btr = btr->next;
            }
            else
            {
                tail->next = atr;
                atr = atr->next;
            }
            tail = tail->next;
        }
        tail->next = (atr ? atr : btr);
        return head.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (int i = 0; i < lists.size(); ++i) {
            ans = mergeTwoList(ans, lists[i]);
        }
        return ans;
    }
};