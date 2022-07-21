//> 最大体积值

#include <iostream>
#include <vector>
using namespace std;



bool isPrime(long long x)
{
    for (long i = 2; i <= sqrt(x); ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
long long getMaxVolume(long long n) {
    // write code here
    vector<long long> res;
    long long maxSum = 0;
    for (long long i = 2; i <= n; ++i)
    {
        if (isPrime(i) == true)
            res.emplace_back(i);
    }
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = i; j < res.size(); ++j)
        {
            for (int k = j; k < res.size(); ++k)
            {
                if (res[i] + res[j] + res[k] == n)
                {
                    long long num = res[i] * res[j] * res[k];
                    maxSum = num > maxSum ? num : maxSum;
                }
            }
        }
    }
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
    return maxSum;
}

int main()
{
    int x;
    while (cin >> x)
        cout << getMaxVolume(x) << endl;

}


//> 滑动窗口的最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k - 1;
        vector<int> res;
        while (right < nums.size())
        {
            int maxValue = nums[left];
            for (int i = left; i <= right; ++i)
            {
                maxValue = max(maxValue, nums[i]);
            }
            res.emplace_back(maxValue);
            left++;
            right++;
        }
        return res;
    }
};


//> 左旋转字符串
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};