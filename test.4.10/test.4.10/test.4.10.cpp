//> 不同路径 III
class Solution {
public:
    void DFS(int x, int y, int zero_count, int& path_count, vector<vector<int>>& grid)
    {
        //> 判断是否越界
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        //> 为障碍，则结束
        if (grid[x][y] == -1)
            return;
        //> 不仅要走到结束方格，还要每一个无障碍方格走一边
        if (grid[x][y] == 2 && zero_count != 0)
            return;

        if (grid[x][y] == 2 && zero_count == 0)
        {
            path_count++;
            return;
        }

        int temp = grid[x][y];
        //> 标记走过
        grid[x][y] = -1;
        //> 开始回溯
        DFS(x - 1, y, zero_count - 1, path_count, grid);
        DFS(x + 1, y, zero_count - 1, path_count, grid);
        DFS(x, y - 1, zero_count - 1, path_count, grid);
        DFS(x, y + 1, zero_count - 1, path_count, grid);
        grid[x][y] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        //> 找到入口
        int x, y;
        path_count = 0;
        zero_count = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                    zero_count++;
                }
                if (grid[i][j] == 0)
                    zero_count++;
            }
        }
        //> 参数，起始坐标x，y，当前还需走过的空方格，路径条数，二维网格
        DFS(x, y, zero_count, path_count, grid);
        return path_count;
    }
private:

    int path_count;
    int zero_count;
};

//> 整数拆分
class Solution {
public:
    int integerBreak(int n) {
        //> dp[i] : 正整数i拆分的最大乘积
        vector<int> dp(n + 1);
        //> 初始化：最小的拆解数字为 2，dp[2] = 1;
        dp[2] = 1;
        //> dp方向：从 1 -> n
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i - 1; ++j)
            {
                //> dp[i]状态转移方程：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
