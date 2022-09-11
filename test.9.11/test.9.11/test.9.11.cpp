
// ÕûÊıÌæ»»
class Solution {
public:
    int dfs(long long n)
    {
        if (n == 1)
            return 0;

        if (n & 1)
        {
            return min(dfs((n + 1) / 2), dfs((n - 1) / 2)) + 2;
        }
        else
        {
            return dfs(n >> 1) + 1;
        }
    }
    int integerReplacement(int n) {
        return dfs(n);
    }

};