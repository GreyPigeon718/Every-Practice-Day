
//> 打印从1到最大的n位数
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for (int i = 1; i < pow(10, n); ++i)
        {
            res.emplace_back(i);
        }
        return res;
    }
};


//> 删除链表的节点
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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
            return head->next;
        ListNode* cur = head, * pre = NULL;
        while (cur)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
                return head;
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

//>  正则表达式匹配
class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size(), n = p.size();

        //> dp[i][j]表示：s前i个字符与p的前j个字符是否匹配
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        //> 初始化：dp[0][0] = true;
        dp[0][0] = true;

        //> s一个字符都不选，此时要考虑p包含*的情况，因为*可以不匹配
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        //> 遍历顺序：先s后p
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //> 状态转移方程:
                //> 当 p[j-1] != '*', dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
                //> 当 p[j-1] == '*',分两种情况：第一种匹配0次，也就是不匹配；第二种匹配n次（n=1,2,3,..）
                //> 第一种情况 dp[i][j] = dp[i][j-2];
                //> 第二种情况 dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.')
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};