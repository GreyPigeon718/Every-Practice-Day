// 查找数字
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
////isdigit
//int main()
//{
//	string s;
//	vector<int> v;
//	while (getline(cin, s))
//	{
//		v.clear();
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (isdigit(s[i]))
//			{
//				s[i] = s[i] - '0';
//				v.push_back(s[i]);
//			}
//		}
//		for (int j = 0; j < v.size(); ++j)
//			cout << v[j];
//		cout << endl;
//	}
//
//	return 0;
//}
//寻找中间节点
#include <iostream>
 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* quick = slow;
        while (quick->next != NULL && quick != NULL)
        {
            slow = slow->next;
            quick = quick->next->next;
        }
        return slow;
    }
};
//删除链表的倒数第N个节点
class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
