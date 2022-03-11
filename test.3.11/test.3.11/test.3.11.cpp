//> 股票的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int MinPro = INT_MAX;
        for (auto e : prices)
        {
            res = max(res, e - MinPro);
            MinPro = min(MinPro, e);
        }
        return res;
    }
};

//> 分发糖果
class Solution {
public:
    int candy(vector<int>& ratings) {
        //> 贪心算法，先局部最优解->全局最优解
        //> 从前到后，确定相邻的右大于左
        //> 从后到前，确定相邻的左大于右
        //> 进行比较，最少糖果数目
        int sum = 0;
        vector<int> v(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i)
        {
            if (ratings[i + 1] > ratings[i])
                v[i + 1] = v[i] + 1;
        }

        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
                v[i] = max(v[i], v[i + 1] + 1);
        }
        for (auto e : v)
            sum += e;
        return sum;
    }
};