//动态规划
class Coins {
public:
    int countWays(int n) {
        // write code here
        int coins[4] = { 1,5,10,25 };
        int dp[100001] = { 0 };
        dp[0] = 1;
        for (int i = 0; i < 4; ++i) {
            for (int j = coins[i]; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }
        return dp[n];
    }
};
//链表中的入口节点
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
