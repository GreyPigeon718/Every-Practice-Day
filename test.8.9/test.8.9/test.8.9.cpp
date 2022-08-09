//> ����֮�� II - ������������
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, sum;

        while (l < r)
        {
            sum = numbers[l] + numbers[r];
            if (sum == target)
                break;
            if (sum > target)
                --r;
            else
                ++l;

        }
        return { l + 1, r + 1 };
    }
};

//> �ϲ�������������
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = m-- + n-- - 1;
        while (m >= 0 && n >= 0)
        {
            nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0)
            nums1[pos--] = nums2[n--];
    }
};

//> ��������
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
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> ust;

        while (head)
        {
            if (ust.count(head))
            {
                return head;
            }
            ust.insert(head);
            head = head->next;
        }
        return NULL;
    }
};


//> ����ˮ
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            // ��һ�����Ӻ����һ�����Ӳ�����ˮ
            if (i == 0 || i == height.size() - 1) continue;

            int rHeight = height[i]; // ��¼�ұ����ӵ���߸߶�
            int lHeight = height[i]; // ��¼������ӵ���߸߶�
            for (int r = i + 1; r < height.size(); r++) {
                if (height[r] > rHeight) rHeight = height[r];
            }
            for (int l = i - 1; l >= 0; l--) {
                if (height[l] > lHeight) lHeight = height[l];
            }
            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) sum += h;
        }
        return sum;
    }
};