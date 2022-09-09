#include <iostream>

using namespace std;

int main()
{
	unsigned char i = 1;
	cout << i-=3;
}
//  ÕûÊýÌæ»»
class Solution {
public:
    int dfs(long long n, unordered_map<int, int>& memo) {
        if (n == 1) return 0;
        if (memo.count(n)) return memo[n];
        int res = 0;
        if (n & 1) {
            res = min(dfs(n + 1, memo), dfs(n - 1, memo));
        }
        else {
            res = dfs(n >> 1, memo);
        }
        memo[n] = res + 1;
        return memo[n];
    }
    int integerReplacement(int n) {
        unordered_map<int, int> memo;
        return dfs((long long)n, memo);
    }
};
