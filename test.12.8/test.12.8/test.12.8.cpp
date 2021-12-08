// 有效的括号字符串
class Solution {
public:
    bool checkValidString(string s) {
        int Max_count = 0, Min_count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            if (c == '(')
            {
                Max_count++;
                Min_count++;
            }
            else if (c == ')')
            {
                Max_count--;
                Min_count = max(Min_count - 1, 0);
                if (Max_count < 0)
                    return false;
            }
            else
            {
                Max_count++;
                Min_count = max(Min_count - 1, 0);
            }
        }
        if (Min_count == 0)
            return true;
        return false;

    }
};
// 链表求和
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* res = new ListNode(-1);
        ListNode* res_cur = res;
        int flag = 0;
        while (cur1 || cur2)
        {
            int sum = (cur1 ? cur1->val : 0) + (cur2 ? cur2->val : 0) + flag;
            ListNode* temp = new ListNode(sum % 10);
            res_cur->next = temp;
            res_cur = res_cur->next;
            flag = sum / 10;
            cur1 = cur1 ? cur1->next : cur1;
            cur2 = cur2 ? cur2->next : cur2;
        }
        if (flag)
            res_cur->next = new ListNode(1); //最后的进位
        return res->next;
    }
};

