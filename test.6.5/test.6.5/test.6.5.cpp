//> �����������

int getArea(vector<vector<int>>& grid, int i, int j)
{
    //��������ÿ�� +1 �������ж��Ƿ�������鳤�ȼ���
    if (i == grid.size() || i < 0)
        return 0;
    else if (j == grid[0].size() || j < 0)
        return 0; ;
    if (grid[i][j] == 1)
    {
        grid[i][j] = 0;
        return 1 + getArea(grid, i + 1, j) + getArea(grid, i - 1, j) + getArea(grid, i, j + 1) + getArea(grid, i, j - 1);
    }
    return 0;
}

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    //�Դ�Ϊ���ģ���������ɢ
                    area = getArea(grid, i, j);
                    maxArea = maxArea > area ? maxArea : area;
                }
            }
        }
        return maxArea;
    }
