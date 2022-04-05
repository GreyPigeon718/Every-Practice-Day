
//>买卖股票的最佳时机含手续费
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int minprice = prices[0];
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < minprice)
                minprice = prices[i];

            if (prices[i] >= minprice && prices[i] <= minprice + fee)
                continue;

            if (prices[i] > minprice + fee)
            {
                result += prices[i] - minprice - fee;
                minprice = prices[i] - fee;
            }
        }
        return result;
    }
};