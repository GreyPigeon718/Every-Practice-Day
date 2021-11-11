//合并k个升序链表
#include <iostream>
#include <vector>

using namespace std;

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergTwoList(ListNode* a, ListNode* b)
    {
        if ((!a) || (!b))
            return a ? a : b;
        ListNode head, *tail = &head, *begin = a, *end = b;
        while (begin && end)
        {
            if (begin->val < end->val)
            {
                tail->next = begin;
                begin = begin->next;
            }
            else
            {
                tail->next = end;
                end = end->next;
            }
            tail = tail->next;
        }
        tail->next = (begin ? begin : end);
        return head.next;
        }
    ListNode* merg(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;
        int mid = left + (right - left) / 2;
        return mergTwoList(merg(lists, left, mid), merg(lists, mid + 1, right));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merg(lists, 0, lists.size()-1);
    }
};