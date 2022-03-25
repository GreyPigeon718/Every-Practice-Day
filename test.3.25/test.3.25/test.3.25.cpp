//>  ���°����г�
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
            if (v.second > 0) { // ��¼��������Ƿ�ɹ���
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
            //> ��¼ӳ���ϵ
            umpp[v[0]][v[1]]++;
        }
        res.push_back("JFK");
        backtraversal(tickets.size(), res);
        return res;
    }
private:
    //> �����㣬 ����ص㣬�������
    unordered_map<string, map<string, int>> umpp;
};

//> ����Ԫ��
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

//> �ظ������ַ���
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};


//> N �ʺ�
class Solution {
public:
    bool isinvaild(int row, int col, vector<string>& chessboard, int n)
    {
        //> ��֦�Ż�
        for (int i = 0; i < row; ++i)
        {
            //> ÿһ��
            if (chessboard[i][col] == 'Q')
                return false;
        }

        //> 135��
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (chessboard[i][j] == 'Q')
                return false;
        }

        //> 45��
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
                //> ���ûʺ�
                chessboard[row][col] = 'Q';
                //> ���� �൱��ÿһ��ȡһ������ȥ��
                backtracking(n, row + 1, chessboard);
                //> ȡ���ʺ�
                chessboard[row][col] = '.';

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //> ��ʼ��һ�����̣�ȫ��Ϊ'.' 
        vector<string> chessboard(n, string(n, '.'));
        //> ���̴�С�� ���ݵ�row������ ����
        backtracking(n, 0, chessboard);
        return res;
    }
private:
    vector<vector<string>> res;
};


//> �ַ�����
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //> �ֲ�����->ȫ������
        //> �ֲ����ţ���ߴ���ɸ�θ�ڴ��С��
        //> ȫ�����ţ���������θ�ڴ��С��
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