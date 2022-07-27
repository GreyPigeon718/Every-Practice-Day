//> n�����ӵĵ���

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> res(n * 6 - n + 1);
        vector<vector<int> > dp(n + 1, vector<int>(6 * n + 1, 0)); // ��ȫ��ֵ��ʼ��Ϊ 0
        int row = n + 1, col = 6 * n + 1; //col ==> [0,6n] ��6n+1��
        // ��ʼ����һ������
        // dp[1][1]=1 ����һ�����ӵ�����Ϊ 1 �������һ��
        // dp[1][2]=1 ����һ�����ӵ�����Ϊ 2 �������һ��
        for (int i = 1; i <= 6; i++) {
            dp[1][i] = 1; //��Ϊֻ��һ������ʱ��������Ϊ1,2,3,4,5,6���������ֻ��һ��
        }

        for (int i = 2; i < row; i++) { //��2�����ӿ�ʼ����
            for (int j = i; j < col; j++) { //j���ǵ���֮��s,�Ǵ�i��ʼ�ģ�
                                      //����i�����ӵ���֮�͵���СֵΪi
                for (int k = 1; k <= 6; k++) {
                    //dp[i][j]��ʾ i�����ӵ���֮��Ϊj�������ж��٣�
                    //�𣺵���i�����ӵ���Ϊkʱ����ôǰi-1�����ӵ����ͱ������j-k����k+(j-k)=j;
                    //    ������dp[i-1][j-k]������������(k��[1,6])���͵���dp[i][j]��������
                    if (j - k > 0)  dp[i][j] += dp[i - 1][j - k];
                    else break;
                }
            }
        }

        double denominator = pow(6.0, n); // ��ĸ
        int index = 0;
        for (int k = n; k <= 6 * n; k++) { //������� �����
            res[index++] = dp[n][k] / denominator; //n�����ӣ������Բ���6^n�ֽ��
                                                //���磬2�����ӿ��Բ���C(1,6)*C(1,6)=6*6��
        }
        return res;
    }
};