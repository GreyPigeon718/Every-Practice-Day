// ��������II
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
        if (row1 == row2)//��������б��һ����ֱ�Ӵ���һ�б齫��������
        {
            for (int i = col1; i <= col2; i++)
            {
                ans[row1][i] = num++;
            }
            return;
        }
        //�����
        if (col1 == col2)
        {//ֱ�ӽ���һ�б����������
            for (int i = row1; i <= row2; i++)
            {
                ans[i][col1] = num++;
            }
            return;
        }
        //˵���к��в���Ƚ��߿��ӡ
        //��ǰ��¼һ�·���������
        int rowStart = row1;
        int colStart = col1;
        while (colStart < col2)//��ӡ���ϲ�ı߿�
        {
            ans[row1][colStart++] = num++;
        }
        //��ӡ�����ߵı߿�
        while (rowStart < row2)
        {
            ans[rowStart++][col2] = num++;
        }
        //��ӡ�����ߵ�
        while (colStart > col1)
        {
            ans[row2][colStart--] = num++;
        }
        //������
        while (rowStart > row1)//ע�������Ǵ��ڷ�ֹ�ظ�����
        {
            ans[rowStart][col1] = num++;

            rowStart--;
        }
    }
};