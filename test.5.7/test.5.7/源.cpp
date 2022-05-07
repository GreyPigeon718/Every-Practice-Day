class Solution {
public:
    int numDistinct(string s, string t) {
        //> dp[i][j] ����s�ַ�����i-1Ϊ��βƥ��t�ַ���j-1���ַ����ĸ���
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //> ״̬ת�Ʒ��̷�������� s-1��t-1��ͬ/����ͬ
        //> ��ͬһ���֣�dp[i][j] = dp[i-1][j-1]
        //> ������ͬ�ظ��ַ�:dp[i][j] = dp[i-1][j];
        //> ����ͬ��dp[i][j] = dp[i-1][j]; _____________ϸ�����
        //> dp��ʼ����sΪ��ʱ,�����������ò���t�ַ��������գ�
        //> ����s[0][j] = 0;
        //> tΪ��ʱ��sɾ��һ�ξ���ƥ��
        //> ����s[i][0] = 1;
        //> ��s��t��Ϊ��ʱ��Ӧ�û���1�Σ�s[0][0] = 1;
        for (int i = 0; i < s.size(); ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};