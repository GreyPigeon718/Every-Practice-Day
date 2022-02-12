// 飞地的数量
class Solution {
public:
    void dfs(vector<vector<int>>& A, int i, int j)
    {
        if (i < 0 || i >= A.size() || j < 0 || j >= A[i].size() || A[i][j] == 0)
        {
            return;
        }
        A[i][j] = 0;
        dfs(A, i - 1, j);
        dfs(A, i + 1, j);
        dfs(A, i, j - 1);
        dfs(A, i, j + 1);
    }

    int numEnclaves(vector<vector<int>>& A) {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                if ((i == 0 || j == 0 || i == A.size() - 1 || j == A[0].size() - 1) && A[i][j] == 1)
                {
                    dfs(A, i, j);
                }
            }
        }
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};