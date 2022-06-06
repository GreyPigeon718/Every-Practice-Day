//> 岛屿的最大面积

int getArea(vector<vector<int>>& grid, int i, int j)
{
    //由于坐标每次 +1 ，所以判断是否等于数组长度即可
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
                    //以此为中心，向四周扩散
                    area = getArea(grid, i, j);
                    maxArea = maxArea > area ? maxArea : area;
                }
            }
        }
        return maxArea;
    }
