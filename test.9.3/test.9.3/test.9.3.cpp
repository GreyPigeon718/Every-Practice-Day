#include <iostream>
#include <string>
#include <vector>
// ��Ʒ�ۿۺ�����ռ۸�
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ans(n);
        //> ά��һ������ջ����ջ�׵�ջ������
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


