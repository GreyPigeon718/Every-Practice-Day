// 螺旋矩阵II
class Solution {
public:
    int num = 1;
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n));
        int row1 = 0;
        int col1 = 0;
        int row2 = n - 1;
        int col2 = n - 1;
        while (row1 <= row2 && col1 <= col2)
        {
            Print(ans, row1++, col1++, row2--, col2--);
        }
        return ans;
    }
    void Print(vector<vector<int>>& ans, int row1, int col1, int row2, int col2)
    {
        if (row1 == row2)//两个点的行变成一样了直接从这一行遍将其放入答案中
        {
            for (int i = col1; i <= col2; i++)
            {
                ans[row1][i] = num++;
            }
            return;
        }
        //列相等
        if (col1 == col2)
        {//直接将这一列遍历放入答案中
            for (int i = row1; i <= row2; i++)
            {
                ans[i][col1] = num++;
            }
            return;
        }
        //说明行和列不相等将边框打印
        //提前记录一下方便后序遍历
        int rowStart = row1;
        int colStart = col1;
        while (colStart < col2)//打印最上层的边框
        {
            ans[row1][colStart++] = num++;
        }
        //打印往下走的边框
        while (rowStart < row2)
        {
            ans[rowStart++][col2] = num++;
        }
        //打印往左走的
        while (colStart > col1)
        {
            ans[row2][colStart--] = num++;
        }
        //往上走
        while (rowStart > row1)//注意这里是大于防止重复遍历
        {
            ans[rowStart][col1] = num++;

            rowStart--;
        }
    }
};