//> ������ʽ��ƥ��
class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size(), n = p.size();

        //> dp[i][j]��ʾ��sǰi���ַ���p��ǰj���ַ��Ƿ�ƥ��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        //> ��ʼ����dp[0][0] = true;
        dp[0][0] = true;

        //> sһ���ַ�����ѡ����ʱҪ����p����*���������Ϊ*���Բ�ƥ��
        for (int i = 2; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }

        //> ����˳����s��p
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                //> ״̬ת�Ʒ���:
                //> �� p[j-1] != '*', dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
                //> �� p[j-1] == '*',�������������һ��ƥ��0�Σ�Ҳ���ǲ�ƥ�䣻�ڶ���ƥ��n�Σ�n=1,2,3,..��
                //> ��һ����� dp[i][j] = dp[i][j-2];
                //> �ڶ������ dp[i][j]=dp[i][j-2]||dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.')
                if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[m][n];
    }
};

//> ������������
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //> ���׹�ʽ��s = sqrt(p * (p - a) * (p - b) * (p - c));p = 1/2(a + b + c)
        double maxs = 0.0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int s = j + 1; s < n; s++) {
                    double a = sqrt(pow(abs(points[j][0] - points[i][0]), 2) + pow(abs(points[j][1] - points[i][1]), 2));
                    double b = sqrt(pow(abs(points[s][0] - points[j][0]), 2) + pow(abs(points[s][1] - points[j][1]), 2));
                    double c = sqrt(pow(abs(points[i][0] - points[s][0]), 2) + pow(abs(points[i][1] - points[s][1]), 2));
                    double l = (a + b + c) * 0.5;
                    maxs = max(maxs, sqrt(l * (l - a) * (l - b) * (l - c)));
                }
            }
        }
        return maxs;
    }
};
