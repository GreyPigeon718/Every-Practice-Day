//判断给定的链表中是否有环。如果有环则返回true，否则返回false。
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if (head == NULL)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && (fast->next) != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};
//输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        ListNode* a = pHead1;
        ListNode* b = pHead2;
        while (a != b)
        {
            a = a ? a->next : pHead2;
            b = b ? b->next : pHead1;
        }
        return a;
    }
};