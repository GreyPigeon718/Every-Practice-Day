#include <iostream>
#include <string>
#include <vector>
// 商品折扣后的最终价格
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ans(n);
        //> 维护一个单调栈，从栈底到栈顶升序
        stack<int> sk;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!sk.empty() && sk.top() > prices[i])
            {
                sk.pop();
            }
            ans[i] = sk.empty() ? prices[i] : prices[i] - sk.top();
            sk.emplace(prices[i]);
        }
        return ans;
    }
};


