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
        //> dp[i]: [0, i]区间前i个信封的最大高度
        vector<int> dp(envelopes.size(), 0);
        //> 先排序
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {return a[0] > b[0]; });
        //> 初始化:dp[i] = 0 
        //> 遍历顺序：逐个信封
        int res = 0;
        for (int i = 0; i < envelopes.size(); ++i)
        {
            int height = 0;
            for (int j = 0; j < i; ++j)
            {
                //> 之前信封是否能装下该信封
                if (envelopes[j][0] > envelopes[i][0]
                    && envelopes[j][1] > envelopes[i][1])
                    //> 是否是之前区间的最大高度 
                    height = max(dp[j], height);
            }
            //> 状态转移方程： dp[i] = max(dp[j], height) + 1;
            dp[i] = height + 1;
            res = max(dp[i], res);
        }
        return res;
    }
};