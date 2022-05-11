//> �༭����
class Solution {
public:
    int minDistance(string word1, string word2) {
        //> dp[i][j]:��ʾ���±�i-1Ϊ��β���ַ���word1��
        //> ���±�j-1Ϊ��β���ַ���word2�����ٵĲ�������
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //> ��ʼ��: dp[i][0] = i,dp[0][j] = j;
        for (int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); ++j)
            dp[0][j] = j;
        //> ����˳�� ��word1��word2�������ԣ�
        for (int i = 1; i <= word1.size(); ++i)
        {
            for (int j = 1; j <= word2.size(); ++j)
            {
                //> ״̬ת�Ʒ��̣�
                //> word[i-1] == word[j-1], dp[i][j] = dp[i-1][j-1]
                //> word[i-1] ��= word[j-1]
                //> dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}+1)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};