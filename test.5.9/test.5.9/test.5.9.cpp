class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row1 = 0;
        int col1 = 0;
        int row2 = matrix.size() - 1;
        int col2 = matrix[0].size() - 1;
        while (row1 < row2)//如果他们相等了说明不用旋转了
        {
            Rotate(matrix, row1++, col1++, row2--, col2--);
        }


    }
    void Rotate(vector<vector<int>>& matrix, int row1, int col1, int row2, int col2)
    {
        for (int i = 0; i < col2 - col1; i++)
        {
            int tmp = matrix[row1][col1 + i];//旋转的第一个元素
            matrix[row1][col1 + i] = matrix[row2 - i][col1];//这一组最后一个元素覆盖第一个位置
            matrix[row2 - i][col1] = matrix[row2][col2 - i];//依次覆盖
            matrix[row2][col2 - i] = matrix[row1 + i][col2];
            matrix[row1 + i][col2] = tmp;//将第一个元素放到正确的位置
        }

    }
};