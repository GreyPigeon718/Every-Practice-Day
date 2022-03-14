//> ���ֲ���
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right--;
            else if (nums[mid] < target)
                left++;
            else
                return mid;
        }
        return -1;
    }
};
//> Ѱ�ҷ�ֵ
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        // һֱ��֤[left, right]�н�
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid��mid+1���бȽϣ����ж����µķ���
            // ���mid+1��˵�����ں���
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            // mid�󣬷���ǰ��
            else
                right = mid;
        }
        // �˳���������left == right��ʱ��[left, right]�з壬�����right
        return right;
    }
};

//> ��ת����
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
        ListNode* tmp = head;
        ListNode* pre = NULL;
        while (tmp)
        {
            ListNode* cur = tmp->next;
            tmp->next = pre;
            pre = tmp;
            tmp = cur;
        }
        return pre;
    }
};

//> ��Ч������
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};
