#include <iostream>
#include <vector>

#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int* p = NULL;
	long long* q = NULL;
	int a[10] = { 0 };
	cout << sizeof(p) << endl;
	cout << sizeof(q) << endl;
	cout << sizeof(a) << endl;


}

// »ØÎÄÁ´±í
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
    bool isPalindrome(ListNode* head) {
        vector<int> NodeNum;
        while (head != nullptr)
        {
            NodeNum.emplace_back(head->val);
            head = head->next;
        }

        for (int i = 0, j = NodeNum.size() - 1; i < j; ++i, --j)
        {
            if (NodeNum[i] != NodeNum[j])
                return false;
        }
        return true;
    }
};