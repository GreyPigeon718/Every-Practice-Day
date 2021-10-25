//sËÑË÷¶şÎ¬¾ØÕó
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col = matrix.size();
        int row = matrix[0].size();
        int i = 0;
        int j = row - 1;
        while (j >= 0 && i < col)
        {
            if (target < matrix[i][j])
                j--;
            else if (target > matrix[i][j])
                i++;
            else
                return true;
        }
        return false;
    }
};