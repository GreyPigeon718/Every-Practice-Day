//> n个骰子的点数

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res(n * 6 - n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1, 0)); // 将全部值初始化为 0
        int row = n + 1, col = 6 * n + 1; //col ==> [0,6n] 共6n+1列
        // 初始化第一个骰子
        // dp[1][1]=1 代表一个骰子点数和为 1 的情况有一种
        // dp[1][2]=1 代表一个骰子点数和为 2 的情况有一种
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1; //因为只有一个骰子时，点数和为1,2,3,4,5,6的情况都各只有一种
        }

        for (int i = 2; i < row; i++) { //从2颗骰子开始计算
            for (int j = i; j < col; j++) { //j就是点数之和s,是从i开始的，
                                      //代表i个骰子点数之和的最小值为i
                for (int k = 1; k <= 6; k++) {
                    //dp[i][j]表示 i个骰子点数之和为j的数量有多少？
                    //答：当第i个骰子点数为k时，那么前i-1个骰子点数和必须等于j-k，则k+(j-k)=j;
                    //    把所有dp[i-1][j-k]的数量加起来(k∈[1,6])，就等于dp[i][j]的数量了
                    if (j - k > 0)  dp[i][j] += dp[i - 1][j - k];
                    else break;
                }
            }
        }

        double denominator = pow(6.0, n); // 分母
        int index = 0;
        for (int k = n; k <= 6 * n; k++) { //计算概率 放入答案
            res[index++] = dp[n][k] / denominator; //n个骰子，共可以产生6^n种结果
                                                //比如，2个骰子可以产生C(1,6)*C(1,6)=6*6种
        }
        return res;
    }
};