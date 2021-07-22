//重塑矩阵
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if (row * col != r * c)
            return mat;

        vector<vector<int>> ans(r, vector<int>(c, 0));
        int ti = 0, tj = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                ans[ti][tj++] = mat[i][j];
                if (tj >= c)
                {
                    tj = 0;
                    ti += 1;
                }
            }
        }
        return ans;
    }
};
//杨辉三角
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ret[i].resize(i + 1);
            ret[i][0] = 1;
            ret[i][i] = 1;
            for (int j = 1; j < i; j++)
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
        }
        return ret;
    }
};
//反转字符串中的单词
class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        int i = 0;
        while (i < length)
        {
            int start = i;
            while (s[i] != ' ' && i < length)
            {
                ++i;
            }
            int left = start, right = i - 1;
            while (left < right)
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            //while(s[i] == ' '&& i < length)
            ++i;
        }
        return s;
    }
};