// 构建乘积数组

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 1);
        for (int i = 1; i < a.size(); ++i)
        {
            res[i] = res[i - 1] * a[i - 1];
        }
        int tmp = 1;
        for (int j = a.size() - 2; j >= 0; --j)
        {
            tmp *= a[j + 1];
            res[j] *= tmp;
        }
        return res;
    }
};
// 格雷编码
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);

        int delta = 2;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = delta - 1; j >= 0; --j)
            {
                res.push_back(delta + res[j]);
            }
            delta *= 2;
        }
        return res;
    }
};