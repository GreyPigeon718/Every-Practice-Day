//> ���������ֵ
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //> dp[i][j] : �ߵ�[i,j]�����õ����������ֵ
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        //> ��ʼ����dp[0][0] = grid[0][0]
        //> dp[0][j] = dp[0][j - 1] + grid[0][j]
        //> dp[i][0] = dp[i - 1][0] + grid[i][0]
        dp[0][0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        //> ִ��˳�򣺴����ϵ�����
        for (int i = 1; i < grid.size(); ++i)
        {
            for (int j = 1; j < grid[0].size(); ++j)
            {
                //> ״̬ת�Ʒ��̣�dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j]
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

//> ������ظ��ַ������ַ���
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int res = 0;
        unordered_set<char> udt;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i != 0)
                udt.erase(s[i - 1]);
            while (right < s.size() && udt.count(s[right]) != 1)
            {
                udt.insert(s[right]);
                right++;
            }

            res = max(res, right - i);
        }
        return res;
    }
};

//> ��һ��ֻ����һ�ε��ַ�
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for (char ch : s) {
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i]] == 1) {
                return s[i];
            }
        }
        return ' ';
    }
};

