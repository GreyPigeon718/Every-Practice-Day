//>  重新安排行程
class Solution {
public:
    bool backtraversal(int num, vector<string>& res)
    {
        if (res.size() == num + 1)
        {
            return true;
        }
        for (pair<const string, int>& v : umpp[res[res.size() - 1]])
        {
            if (v.second > 0) { // 记录到达机场是否飞过了
                res.push_back(v.first);
                v.second--;
                if (backtraversal(num, res))
                    return true;
                res.pop_back();
                v.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for (const vector<string>& v : tickets)
        {
            //> 记录映射关系
            umpp[v[0]][v[1]]++;
        }
        res.push_back("JFK");
        backtraversal(tickets.size(), res);
        return res;
    }
private:
    //> 出发点， 到达地点，航班次数
    unordered_map<string, map<string, int>> umpp;
};

//> 多数元素
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int s = 1;
        int k = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == k)
                s++;
            else
            {
                if (s > 0)
                    s--;
                else
                {
                    s = 1;
                    k = nums[i];
                }
            }
        }
        return k;
    }
};

//> 重复的子字符串
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};


//> N 皇后
class Solution {
public:
    bool isinvaild(int row, int col, vector<string>& chessboard, int n)
    {
        //> 剪枝优化
        for (int i = 0; i < row; ++i)
        {
            //> 每一列
            if (chessboard[i][col] == 'Q')
                return false;
        }

        //> 135°
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        //> 45°
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void backtracking(int n, int row, vector<string>& chessboard)
    {
        if (n == row)
        {
            res.push_back(chessboard);
            return;
        }

        for (int col = 0; col < n; ++col)
        {
            if (isinvaild(row, col, chessboard, n))
            {
                //> 放置皇后
                chessboard[row][col] = 'Q';
                //> 回溯 相当于每一行取一个，行去重
                backtracking(n, row + 1, chessboard);
                //> 取消皇后
                chessboard[row][col] = '.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //> 初始化一个棋盘，全部为'.' 
        vector<string> chessboard(n, string(n, '.'));
        //> 棋盘大小， 回溯到row层数， 棋盘
        backtracking(n, 0, chessboard);
        return res;
    }
private:
    vector<vector<string>> res;
};


//> 分发饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //> 局部最优->全局最优
        //> 局部最优：大尺寸饼干给胃口大的小孩
        //> 全局最优：优先满足胃口大的小孩
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int index = s.size() - 1;
        for (int i = g.size() - 1; i >= 0; --i)
        {
            if (index >= 0 && s[index] >= g[i])
            {
                index--;
                result++;
            }
        }
        return result;
    }
};