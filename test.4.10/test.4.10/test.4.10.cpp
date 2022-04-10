//> ��ͬ·�� III
class Solution {
public:
    void DFS(int x, int y, int zero_count, int& path_count, vector<vector<int>>& grid)
    {
        //> �ж��Ƿ�Խ��
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        //> Ϊ�ϰ��������
        if (grid[x][y] == -1)
            return;
        //> ����Ҫ�ߵ��������񣬻�Ҫÿһ�����ϰ�������һ��
        if (grid[x][y] == 2 && zero_count != 0)
            return;

        if (grid[x][y] == 2 && zero_count == 0)
        {
            path_count++;
            return;
        }

        int temp = grid[x][y];
        //> ����߹�
        grid[x][y] = -1;
        //> ��ʼ����
        DFS(x - 1, y, zero_count - 1, path_count, grid);
        DFS(x + 1, y, zero_count - 1, path_count, grid);
        DFS(x, y - 1, zero_count - 1, path_count, grid);
        DFS(x, y + 1, zero_count - 1, path_count, grid);
        grid[x][y] = temp;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        //> �ҵ����
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
        //> ��������ʼ����x��y����ǰ�����߹��Ŀշ���·����������ά����
        DFS(x, y, zero_count, path_count, grid);
        return path_count;
    }
private:

    int path_count;
    int zero_count;
};

//> �������
class Solution {
public:
    int integerBreak(int n) {
        //> dp[i] : ������i��ֵ����˻�
        vector<int> dp(n + 1);
        //> ��ʼ������С�Ĳ������Ϊ 2��dp[2] = 1;
        dp[2] = 1;
        //> dp���򣺴� 1 -> n
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i - 1; ++j)
            {
                //> dp[i]״̬ת�Ʒ��̣�dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
                dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            }
        }
        return dp[n];
    }
};
