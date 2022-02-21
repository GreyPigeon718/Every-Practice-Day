//> 推多米诺
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        //> 队列使用BFS
        queue<int> q;
        //> 数组time \记录骨牌翻倒或者确定不翻倒的时间，翻倒的骨牌不会对正在翻倒或者已经翻倒的骨牌施加力；
        vector<int> time(n, -1);
        //> 数组 force记录骨牌受到的力，骨牌仅在受到单侧的力时会翻倒。
        vector<string> force(n);
        for (int i = 0; i < n; i++) {
            if (dominoes[i] != '.') {
                q.emplace(i);
                time[i] = 0;
                force[i].push_back(dominoes[i]);
            }
        }

        string res(n, '.');
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (force[i].size() == 1) {
                char f = force[i][0];
                res[i] = f;
                int ni = (f == 'L') ? (i - 1) : (i + 1);
                if (ni >= 0 and ni < n) {
                    int t = time[i];
                    if (time[ni] == -1) {
                        q.emplace(ni);
                        time[ni] = t + 1;
                        force[ni].push_back(f);
                    }
                    else if (time[ni] == t + 1) {
                        force[ni].push_back(f);
                    }
                }
            }
        }
        return res;
    }
};


//> 二进制矩阵中的最短路径
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        if (grid[0][0] == 1 || grid[size - 1][size - 1] == 1)
            return -1;
        const int dire[8][2] = { {0,1}, {0,-1}, {-1,0}, {1,0}, {-1,1}, {1,1}, {1,-1},{-1,-1} };
        queue<pair<int, int>> point;
        int res = 1;
        point.emplace(0, 0);
        //> 每个走过的0都变为1
        grid[0][0] = 1;
        while (!point.empty())
        {
            int len = point.size();
            while (len--)
            {
                cout << len;
                auto [x, y] = point.front();
                point.pop();
                if (x == size - 1 && y == size - 1)
                    return res;
                //> 遍历八个方向
                for (int i = 0; i < 8; ++i)
                {
                    int dirx = x + dire[i][0];
                    int diry = y + dire[i][1];
                    //> 如果越界跳过该方向
                    if (dirx < 0 || diry < 0 || dirx >= size || diry >= size)
                        continue;
                    if (grid[dirx][diry] == 0)
                    {
                        point.emplace(dirx, diry);
                        grid[dirx][diry] = 1;
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
//> 被围绕的区域

//> 题解1 BFS
class Solution {
public:
    const int dx[4] = { 1, -1, 0, 0 };
    const int dy[4] = { 0, 0, 1, -1 };

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) {
            return;
        }
        int m = board[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                que.emplace(i, 0);
                board[i][0] = 'A';
            }
            if (board[i][m - 1] == 'O') {
                que.emplace(i, m - 1);
                board[i][m - 1] = 'A';
            }
        }
        for (int i = 1; i < m - 1; i++) {
            if (board[0][i] == 'O') {
                que.emplace(0, i);
                board[0][i] = 'A';
            }
            if (board[n - 1][i] == 'O') {
                que.emplace(n - 1, i);
                board[n - 1][i] = 'A';
            }
        }
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx < 0 || my < 0 || mx >= n || my >= m || board[mx][my] != 'O') {
                    continue;
                }
                que.emplace(mx, my);
                board[mx][my] = 'A';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

//> 题解2 DFS
class Solution {
public:
    int row, col;
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if (x < 0 || y < 0 || x >= row || y >= col || board[x][y] != 'O')
            return;
        //> 进行标记，改为“A”
        board[x][y] = 'A';
        //> 进行周围上下左右的判断
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if (row == 0)
            return;
        col = board[0].size();

        //>  从边界出发，先从左右，最左一列，最右一列
        for (int i = 0; i < row; ++i)
        {
            dfs(board, i, 0);
            dfs(board, i, col - 1);
        }
        //> 然后上下，最上一行，最下一行
        for (int j = 1; j < col - 1; ++j)
        {
            dfs(board, 0, j);
            dfs(board, row - 1, j);
        }
        //> 然后完整进行遍历，被标记则改为“o”,未被标记则改为“X”
        for (int x = 0; x < row; ++x)
        {
            for (int y = 0; y < col; ++y)
            {
                if (board[x][y] == 'A')
                    board[x][y] = 'O';
                else if (board[x][y] == 'O')
                    board[x][y] = 'X';
            }
        }
    }
};