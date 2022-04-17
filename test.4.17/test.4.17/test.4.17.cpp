//> 最常见的单词
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ut;
        for (string& word : banned)
        {
            ut.emplace(word);
        }
        int maxfrequency = 0;
        unordered_map<string, int> up;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; ++i)
        {
            if (i < length && isalpha(paragraph[i]))
                word.push_back(tolower(paragraph[i]));
            else if (word.size() > 0)
            {
                if (ut.count(word) != 1)
                {
                    up[word]++;
                    maxfrequency = max(maxfrequency, up[word]);
                }
                word = "";
            }
        }
        string res = "";
        for (auto& [word, frequency] : up)
        {
            if (frequency == maxfrequency)
            {
                res = word;
                break;
            }
        }
        return res;
    }
};


//> 最小路径和
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        //> dp[i][j] : 从（0 , 0）到 （i , j）的最小数字和
        vector<vector<long>> dp(grid.size(), vector<long>(grid[0].size(), 0));
        //> 初始化：dp[0][0] = 0
        dp[0][0] = grid[0][0];
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 1; i < row; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        //> dp[i][0] = dp[i-1][0] + grid[i][0]
        //> dp[i][0] = dp[0][j-1] + grid[0][j]
        for (int j = 1; j < col; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        //> 遍历顺序：行 -> 列
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < col; ++j)
            {
                //> dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[row - 1][col - 1];
    }
};
