//> �绰�������ĸ���
class Solution {
public:
    const string smap[10] = { "",
                        "",
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz" };
    void backtricking(string& digits, int x)
    {
        if (digits.size() == x)
        {
            res.push_back(s);
            return;
        }
        int digit = digits[x] - '0';
        string sn = smap[digit];
        for (int i = 0; i < sn.size(); ++i)
        {
            s.push_back(sn[i]);
            backtricking(digits, x + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        res.clear();
        s.clear();
        if (digits.size() == 0)
            return res;
        backtricking(digits, 0);
        return res;
    }
private:
    vector<string> res;
    string s;
};

//> ������ת��ĸ 
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left = 0;
        int right = s.size() - 1;
        //> ����˫ָ��
        while (left < right)
        {
            while (!isalpha(s[left]) && left < right)
                ++left;

            while (!isalpha(s[right]) && left < right)
                --right;
            if (left >= right)
                break;
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};

//> ��������
class Solution {
public:
    void backtracking(int n, int open, int close)
    {
        if (s.size() == n * 2)
        {
            res.push_back(s);
            return;
        }
        if (open < n)
        {
            s.push_back('(');
            backtracking(n, open + 1, close);
            s.pop_back();
        }
        if (close < open)
        {
            s.push_back(')');
            backtracking(n, open, close + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return res;
        backtracking(n, 0, 0);
        return res;
    }
private:
    vector<string> res;
    string s;
};

//>  �������� 
class Solution {
public:
    //> �������飬��������
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    bool exist(vector<vector<char>>& board, string word) {
        //> ˫��ѭ����ÿ���㿪ʼ
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    //> n��ʾword��ĵ�n����ĸ�� xy��ʾ��ά����ĺ�������
    bool dfs(vector<vector<char>>& board, string& word, int n, int x, int y)
    {
        if (word[n] != board[x][y])
            return false;
        if (n == word.size() - 1)
            return true;
        //> ��ʱ�����ֵ
        char tmp = board[x][y];
        //> ���б�ǣ���ʾ��������
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i)
        {
            int a = dx[i] + x;
            int b = dy[i] + y;
            //> �Ƿ�Խ�磬�����Ƿ��Ѿ�������
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.')
                continue;
            if (dfs(board, word, n + 1, a, b))
                return true;
        }
        board[x][y] = tmp;
        return false;
    }
};

