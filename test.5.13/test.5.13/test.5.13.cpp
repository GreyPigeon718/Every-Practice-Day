//> һ�α༭
class Solution {
public:
    bool oneEditAway(string first, string second) {

        vector<vector<int>> dp(first.size() + 1, vector<int>(second.size() + 1));
        for (int i = 0; i < first.size(); ++i) dp[i][0] = i;
        for (int i = 0; i < second.size(); ++i) dp[0][i] = i;
        for (int i = 1; i <= first.size(); ++i)
        {
            for (int j = 1; j <= second.size(); ++j)
            {
                if (first[i - 1] == second[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
            }
        }
        if (dp[first.size()][second.size()] <= 1)
            return true;
        return false;
    }
};

class Solution {
public:
    bool oneEditAway(string first, string second) {
        const int M = first.size();
        const int N = second.size();
        if (M > N + 1 || N > M + 1) return false;
        if (N == M + 1) {
            return oneEditAway(second, first);
        }
        int i = 0, j = 0;
        int diff = 0;
        while (i < M && j < N) {
            if (first[i] != second[j]) {
                diff++;
                if (diff >= 2) {
                    return false;
                }
                if (M > N) {
                    j--;
                }
            }
            i++;
            j++;
        }
        return true;
    }
};
