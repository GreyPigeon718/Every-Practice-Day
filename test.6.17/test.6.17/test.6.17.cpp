#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string Reverse(string & s)
{
    int left = 0;
    int j = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            reverse(s.begin() + left, s.begin() + i);
            left = i + 1;
        }
    }
    reverse(s.begin() + left, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    
    cout << Reverse(s) << endl;
    return 0;
}


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //> dp[i]: [0, i]����ǰi���ŷ�����߶�
        vector<int> dp(envelopes.size(), 0);
        //> ������
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0]; });
        //> ��ʼ��:dp[i] = 0 
        //> ����˳������ŷ�
        int res = 0;
        for (int i = 0; i < envelopes.size(); ++i)
        {
            int height = 0;
            for (int j = 0; j < i; ++j)
            {
                //> ֮ǰ�ŷ��Ƿ���װ�¸��ŷ�
                if (envelopes[j][0] > envelopes[i][0]
                    && envelopes[j][1] > envelopes[i][1])
                    //> �Ƿ���֮ǰ��������߶� 
                    height = max(dp[j], height);
            }
            //> ״̬ת�Ʒ��̣� dp[i] = max(dp[j], height) + 1;
            dp[i] = height + 1;
            res = max(dp[i], res);
        }
        return res;
    }
};