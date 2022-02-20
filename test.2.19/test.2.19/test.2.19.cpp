// ���������
// 1�⣺DFS
class Solution {
public:
private:
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        int row = grid.size();
        int col = grid[0].size();

        //> ��ÿ���������ġ�1����תΪ��0��
        grid[x][y] = '0';
        //> ����
        if (x - 1 >= 0 && grid[x - 1][y] == '1')
            dfs(grid, x - 1, y);
        //> ����
        if (x + 1 < row && grid[x + 1][y] == '1')
            dfs(grid, x + 1, y);
        //> ����
        if (y - 1 >= 0 && grid[x][y - 1] == '1')
            dfs(grid, x, y - 1);
        //> ����
        if (y + 1 < col && grid[x][y + 1] == '1')
            dfs(grid, x, y + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        int land = 0;
        //> ����ѭ����������1������DFS
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++land;
                    dfs(grid, i, j);
                }
            }
        }
        return land;
    }
};
//> 2��:BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();

        int island = 0;
        //> ����ѭ��������BFS
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++island;
                    grid[i][j] == '0';
                    queue<pair<int, int>> point;
                    point.push({ i , j });
                    while (!point.empty())
                    {
                        pair<int, int> fpoint = point.front();
                        point.pop();
                        int x = fpoint.first, y = fpoint.second;
                        if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            point.push({ x - 1, y });
                            grid[x - 1][y] = '0';
                        }
                        if (x + 1 < row && grid[x + 1][y] == '1')
                        {
                            point.push({ x + 1, y });
                            grid[x + 1][y] = '0';
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            point.push({ x, y - 1 });
                            grid[x][y - 1] = '0';
                        }
                        if (y + 1 < col && grid[x][y + 1] == '1')
                        {
                            point.push({ x, y + 1 });
                            grid[x][y + 1] = '0';
                        }
                    }
                }
            }
        }
        return island;
    }
};
//> ʡ������
//> DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int res = 0;
        vector<int> v(size);
        queue<int> que;
        for (int i = 0; i < size; ++i)
        {
            if (v[i] == 0)
            {
                que.push(i);
                while (!que.empty())
                {
                    int x = que.front();
                    que.pop();
                    v[x] = 1;
                    for (int j = 0; j < size; ++j)
                    {
                        if (isConnected[x][j] == 1 && v[j] == 0)
                        {
                            que.push(j);
                        }
                    }
                }
                res++;
            }
        }
        return res;
    }
};

//> DFS
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> visited(size);
        int res = 0;
        for (int i = 0; i < size; ++i)
        {
            //> ���δ���ʹ��������DFS
            if (visited[i] == 0)
            {
                res++;
                DFS(isConnected, visited, size, i);
            }
        }
        return res;
    }
private:
    void DFS(vector<vector<int>>& isConnected, vector<int>& visited, int size, int i)
    {
        for (int j = 0; j < size; ++j)
        {
            //> ��ͨͬһ���������Ҳ�δ���ʹ�
            if (isConnected[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                DFS(isConnected, visited, size, j);
            }
        }
    }
};


