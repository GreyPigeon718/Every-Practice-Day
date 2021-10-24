//#include<iostream>
//using namespace std;
//
//bool Match(const char* pattern, const char* str) {
//    //两个字符串同时结束返回true，否则返回false
//    if (*pattern == '\0' && *str == '\0')
//        return true;
//    if (*pattern == '\0' || *str == '\0')
//        return false;
//
//    if (*pattern == '?') {
//        // ? 匹配一个字符，直接跳过一个位置
//        return Match(pattern + 1, str + 1);
//    }
//    else if (*pattern == '*') {
//        // * 匹配0个字符，或者匹配一个字符，或者匹配大于一个字符，一个为真即为真
//        return Match(pattern + 1, str) || Match(pattern + 1, str + 1) || Match(pattern, str + 1);
//    }
//    else if (*pattern == *str) {
//        // 当前字符相等，匹配下一个字符
//        return Match(pattern + 1, str + 1);
//    }
//    return false;
//}
//
//int main() {
//    string pattern;
//    string str;
//    while (cin >> pattern >> str) {
//        if (Match(pattern.c_str(), str.c_str()))
//            cout << "true" << endl;
//        else
//            cout << "false" << endl;
//    }
//    return 0;
//}
//bool isMatch(char* s, char* p)
//{
//    int m = strlen(s);
//    int n = strlen(p);
//    int dp[m + 1][n + 1];
//    memset(dp, 0, sizeof(dp));
//    dp[0][0] = true;
//    for (int i = 1; i <= n; i++)
//    {
//        if (p[i - 1] == '*')
//            dp[0][i] = true;
//        else
//            break;
//    }
//    for (int i = 1; i <= m; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (p[j - 1] == '*')
//                dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
//            else if (p[j - 1] == '?' || s[i - 1] == p[j - 1])
//                dp[i][j] = dp[i - 1][j - 1];
//        }
//    }
//    return dp[m][n];
//}

#include<string>
#include<iostream>
#include<vector>
using namespace std;

int match_string(string m_str, string w_str) //match wildcard 通配符
{
    int m_len = m_str.size();
    int w_len = w_str.size();
    vector<vector<int> > b_dp(w_len + 1, vector<int>(m_len + 1, 0));
    //多加一行一列作为初始初值所用
    b_dp[0][0] = 1;
    for (int i = 1; i <= w_len; i++)
    {
        char ch = w_str[i - 1];
        //设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
            b_dp[i][0] = b_dp[i - 1][0] && (ch == '*');
        for (int j = 1; j <= m_len; j++)
        {
            char ch2 = m_str[j - 1];
            if (ch == '*')
                b_dp[i][j] = b_dp[i - 1][j] || b_dp[i][j - 1]; //当匹配字符为*号时，状态取决于上面状态和左边状态的值
            else
                b_dp[i][j] = b_dp[i - 1][j - 1] && (ch == '?' || ch2 == ch);
        }
    }
    return b_dp[w_len][m_len];
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int ans = match_string(str2, str1);
        if (ans == 1)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
