//> 二分查找
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
//> 寻找峰值
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        // 一直保证[left, right]有解
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid和mid+1进行比较，会判断爬坡的方向
            // 如果mid+1大，说明峰在后面
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            // mid大，峰在前面
            else
                right = mid;
        }
        // 退出条件就是left == right的时候，[left, right]有峰，峰就是right
        return right;
    }
};

//> 反转链表
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

//> 有效的括号
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
