#include<iostream>
#include <vector>
#include <string>

using namespace std;

void func(int* a, int& c)
{
    *a = c;
}
int main()
{
    int b = 1;
    int* a = &b;
    int c = 2;
    func(a, c);
    std::cout << *a << std::endl;
    return 0;
}


//> ]成对的69
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param S string字符串
     * @return string字符串
     */
    string Paired69(string S) {
        // write code here
        int cnt = 0;
        string res = "";
        for (char ch : S)
        {
            if (ch == '6')
                cnt++;
            else
            {
                if (cnt == 0)
                    res += '6';
                else
                    cnt--;
            }
        }
        res += S;
        while (cnt--)
        {
            res += '9';
        }
        return res;
    }
};

//> 最小金额购买商品
class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型
     */
    int cost(vector<int>& array) {
        // write code here
        vector<int> v(array.size(), 1);
        for (int i = 0; i < array.size() - 1; ++i)
        {
            if (array[i + 1] > array[i])
            {
                v[i + 1] = v[i] + 1;
            }
        }
        for (int i = array.size() - 2; i >= 0; --i)
        {
            if (array[i] > array[i + 1])
            {
                v[i] = max(v[i + 1] + 1, v[i]);
            }
        }
        int sum = 0;
        for (auto e : v)
            sum += e;
        return sum;
    }
};


3 4
1 1 2 1
2个人进入同一个食堂 ： (1 / 4 * 2 / 1) * 3 / 4 + (1 / 4 * 1 / 1) * 1 / 4 = 2 / 4
2个人进入不同的食堂 ： 3 / 4 * 1 = 3 / 4

5 5
5 5 5 5 5
// 1 / 5 * 5 = 1;

2 2
1 1
2个人进入同一个食堂 ： 1 / 2 * 2 = 1
2个人进入不同的食堂 ： 1 / 2 * 1 = 1 / 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int a[56];
double dp[56][56][56];
double C[56][56];

int main()
{
    cin >> n >> m;
    C[0][0] = 1.0;
    for (int i = 1; i <= 55; i++)
    {
        C[i][0] = 1.0;
        for (int j = 1; j <= i; j++)
        {
            C[i][j] = (i - j + 1) * C[i][j - 1] / j;
        }
    }
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) dp[0][0][i] = i;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                for (int c = 0; c <= j; c++)
                {
                    int Max = max(k, (c + a[i] - 1) / a[i]);
                    dp[i][j][k] += dp[i - 1][j - c][Max] * pow(i - 1, j - c) / pow(i, j) * C[j][c];
                }
            }
        }
    }
    printf("%.10f\n", dp[m][n][0]);
    return 0;
}

//> 牛牛的奇偶子序列
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

int cal(int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = ((long long)ans * a) % MOD;
            //if (ans < 0) ans += MOD;
        }
        a = (long long)a * a % MOD;
        //if (a < 0) a += MOD;
        n >>= 1;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        //> 保存奇偶性
        nums.emplace_back(x % 2);
    }
    vector<int> ans(n + 1, 0);
    //> 前缀和
    for (int i = 1; i <= n; ++i)
    {
        ans[i] = ans[i - 1] + nums[i - 1];
    }
    for (int j = 0; j < m; ++j)
    {
        int category, left, right;
        cin >> category >> left >> right;
        int odd = ans[right] - ans[left - 1];

        if (category == 1)
        {
            cout << cal(2, odd) - 1 << endl;
        }
        else
        {
            int even = cal(2, right - left + 1) - cal(2, odd);
            if (even < 0)
                even += MOD;
            cout << even << endl;
        }
    }
    return 0;
}