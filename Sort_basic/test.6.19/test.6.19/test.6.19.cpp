//ÄêÖÕ½±
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        for (int i = 1; i < 6; ++i)
        {
            board[0][i] += board[0][i - 1];
            board[i][0] += board[i - 1][0];
        }
        for (int j = 1; j < 6; ++j)
        {
            for (int k = 1; k < 6; ++k)
            {
                board[j][k] += board[j - 1][k] > board[j][k - 1] ? board[j - 1][k] : board[j][k - 1];
            }
        }
        return board[5][5];
    }
};