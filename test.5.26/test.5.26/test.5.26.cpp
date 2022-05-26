
//> ��ӡ��1������nλ��
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


//> ɾ������Ľڵ�
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

//>  ������ʽƥ��
class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size(), n = p.size();

        //> dp[i][j]��ʾ��sǰi���ַ���p��ǰj���ַ��Ƿ�ƥ��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        //> ��ʼ����dp[0][0] = true;
        dp[0][0] = true;

        //> sһ���ַ�����ѡ����ʱҪ����p����*���������Ϊ*���Բ�ƥ��
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        //> ����˳����s��p
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //> ״̬ת�Ʒ���:
                //> �� p[j-1] != '*', dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
                //> �� p[j-1] == '*',�������������һ��ƥ��0�Σ�Ҳ���ǲ�ƥ�䣻�ڶ���ƥ��n�Σ�n=1,2,3,..��
                //> ��һ����� dp[i][j] = dp[i][j-2];
                //> �ڶ������ dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.')
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