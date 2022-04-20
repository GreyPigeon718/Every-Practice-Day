//> 买卖股票的最佳时机 III
//> 没有操作
//> 第一次买入
//> 第一次卖出
//> 第二次买入
//> 第二次卖出

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1))
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        return dp[prices.size() - 1][4];
    }
};
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int buy1 = -prices[0], sell1 = 0;
//         int buy2 = -prices[0], sell2 = 0;
//         for (int i = 1; i < n; ++i) {
//             buy1 = max(buy1, -prices[i]);
//             sell1 = max(sell1, buy1 + prices[i]);
//             buy2 = max(buy2, sell1 - prices[i]);
//             sell2 = max(sell2, buy2 + prices[i]);
//         }
//         return sell2;
//     }
// };

//> 买卖股票的最佳时机 IV
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //> 这个题的解法是买卖股票的最佳时机 III 的进阶版
        //> dp[i][j]: 第i天j状态所剩的最大资金
        //> 本题奇数为买入，偶数为卖出， 0除外
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        for (int i = 1; i < 2 * k + 1; i += 2)
            dp[0][i] = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            for (int j = 0; j < 2 * k - 1; j += 2)
            {
                dp[i][j + 1] = max(dp[i - 1][j] - prices[i], dp[i - 1][j + 1]);
                dp[i][j + 2] = max(dp[i - 1][j + 1] + prices[i], dp[i - 1][j + 2]);
            }
        }
        return dp[prices.size() - 1][2 * k];
    }
};


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
//>  两数相加
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, * tail = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int nums = num1 + num2 + carry;
            if (!head)
            {
                head = tail = new ListNode(nums % 10);
            }
            else
            {
                tail->next = new ListNode(nums % 10);
                tail = tail->next;
            }
            carry = nums / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry > 0)
            tail->next = new ListNode(carry);
        return head;
    }
};

//> 整数反转
class Solution {
public:
    //> 边检查边反转
    int reverse(int x) {
        int res = 0;
        while (x != 0)
        {
            int num = x % 10;
            x /= 10;
            //> int (-21474848 - 2147483647)
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && num > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && num < -8))
                return 0;
            res = res * 10 + num;
        }
        return res;
    }
};

//> 字符串转换整数 (atoi)
class Solution {
public:
    int myAtoi(string s) {
        long res = 0;
        int flag = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            while (s[i] == ' ')
                ++i;
            if (s[i] == '-')
            {
                flag = -1;
                ++i;
            }
            else if (s[i] == '+')
            {
                ++i;
            }
            while (isdigit(s[i]))
            {
                int num = s[i] - '0';
                res = res * 10 + num;
                if (res > INT_MAX && flag == 1)
                    return INT_MAX;
                if (res > INT_MAX && flag == -1)
                    return INT_MIN;
                ++i;
            }

            if (i != s.size() - 1)
                break;
        }
        res *= flag;
        return res;
    }
};



//>  最接近的三数之和
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;
        auto update = [&](int cur)
        {
            if (abs(cur - target) < abs(best - target))
            {
                best = cur;
            }
        };
        //> 枚举第一个数
        for (int i = 0; i < n; ++i)
        {
            //> 保证和上一次数字不同
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            //> 双指针枚举第二个数和第三个数
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                    return target;
                update(sum);
                if (sum > target)
                {
                    //> 移动第二个指针
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k])
                        --k0;
                    k = k0;
                }
                else
                {
                    //> 上面对=判断过了，移动第一个指针
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j])
                        j0++;
                    j = j0;
                }
            }
        }
        return best;
    }
};
