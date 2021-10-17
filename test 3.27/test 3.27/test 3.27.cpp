//�жϸ������������Ƿ��л�������л��򷵻�true�����򷵻�false��
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
//�������������ҳ����ǵĵ�һ��������㡣��ע����Ϊ�����������������Դ���������ݵ���ʾ����������ʽ��ʾ�ģ���֤������������ȷ�ģ�
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