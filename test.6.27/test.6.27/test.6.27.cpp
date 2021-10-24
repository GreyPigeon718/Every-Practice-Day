//螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int top = 0, col = matrix.size() - 1;
        int left = 0, row = matrix[0].size() - 1;
        while (top < (matrix.size() + 1) / 2 && left < (matrix[0].size() + 1) / 2)
        {
            for (int i = left; i <= row; ++i)
            {
                res.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i <= col; ++i)
            {
                res.push_back(matrix[i][row]);
            }
            for (int i = row - 1; top != col && i >= left; --i)
            {
                res.push_back(matrix[col][i]);
            }
            for (int i = col - 1; left != row && i >= top + 1; --i)
            {
                res.push_back(matrix[i][left]);
            }
            ++top, --col, ++left, --row;
        }
        return res;
    }
};

//拍照队形
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, k, m, x, n;
    string line;
    cin >> N;
    char ch;
    vector<char> v;
    x = N;
    while (x--) {
        cin >> ch;
        cin >> noskipws;//在读入第一个字符后可设置读入空格
        v.push_back(ch);
    }
    k = (N - 1) / 3;
    m = 2 * k - 1;
    x = 0, n = 1;
    for (int i = n; i <= k; ++i)
    {
        for (int j = 1; j < n; ++j)
            printf(" ");
        cout << v[x++];
        for (int j = 1; j <= m; ++j)
            printf(" ");
        cout << v[x++] << endl;
        m -= 2;
        n++;
    }
    for (int i = 1; i <= k + 1; ++i)
    {
        for (int j = 1; j <= k; ++j)
            printf(" ");
        cout << v[x++] << endl;
    }
    return 0;
}