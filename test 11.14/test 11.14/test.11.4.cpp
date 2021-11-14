//键值映射
class MapSum {
public:
    MapSum() {

    }

    void insert(string key, int val) {
        cnt[key] = val;
    }

    int sum(string prefix) {
        int res = 0;
        for (auto& [key, val] : cnt)
        {
            if (key.substr(0, prefix.size()) == prefix)
                res += val;
        }
        return res;
    }
private:
    unordered_map<string, int> cnt;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
//相交链表
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> res;
        ListNode* head = headA;
        while (head)
        {
            res.insert(head);
            head = head->next;
        }
        head = headB;
        while (head)
        {
            if (res.count(head))
                return head;
            head = head->next;
        }
        return 0;
    }
};
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headB == nullptr || headA == nullptr)
            return nullptr;
        ListNode* A = headA, * B = headB;
        while (A != B)
        {
            A = A == nullptr ? headB : A->next;
            B = B == nullptr ? headA : B->next;
        }
        return A;
    }
};
//多数元素
// class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int count = 0, res = 0;
        for (int num : nums)
        {
            ++cnt[num];
            if (cnt[num] > count)
            {
                count = cnt[num];
                res = num;
            }
        }
        return res;
    }
};
//快乐数
class Solution {
public:
    bool isHappy(int n) {
        short _n;
        while (n != 0 && n != 1 && n != 4 && n != 16 && n != 37 && n != 58
            && n != 89 && n != 145 && n != 42 && n != 20) {
            _n = 0;
            while (n) {
                _n = _n + pow(n % 10, 2);
                n = n / 10;
            }
            n = _n;
        }
        if (n == 1) return 1;
        else return 0;
    }
};
class Solution {
public:
    int Npow2(int x)
    {
        int sum = 0;
        while (x != 0)
        {
            int a = x % 10;
            sum += a * a;
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> cnt;
        while (1)
        {
            int temp = Npow2(n);
            if (temp == 1)
                return true;
            if (cnt.find(temp) != cnt.end())
                return false;
            else
                cnt.insert(temp);
            n = temp;
        }
        return true;

    }
};