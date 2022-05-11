//> �����ִ�
class Solution {
public:
    int countSubstrings(string s) {

        int result = 0;
        //> dp[i][j]:��ʾ s[i,j]�ַ����Ƿ����
        //> ��ʼ�� dp[i][j] = false;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        //> ����˳�� ���� -> ����
        for (int i = s.size() - 1; i >= 0; --i)
        {
            //> jһ�� ���ڵ��� i
            for (int j = i; j < s.size(); ++j)
            {
                //> ״̬ת�Ʒ��̣�
                //> s[i] == s[j] , j - i <= 1
                //> dp[i][j] = true
                //> if(dp[i+1][j-1] == true)
                //> dp[i][j] = true;
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = true;
                        ++result;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};
//> �����������
class Solution {
public:
    int longestPalindromeSubseq(string s) {


        //> dp[i][j]:��ʾs[i,j]������������г���
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //> ��ʼ�� dp[i][i] = 1;
        for (int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;

        //> ����˳�� ���� --> ����
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < s.size(); ++j)
            {
                //> ״̬ת�Ʒ��̣�s[i] == s[j]
                //> dp[i][j] = dp[i+1][j-1] + 2
                //> s[i] != s[j]
                //> dp[i][j] = max(dp[i+1][j], dp[i][j-1])
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};