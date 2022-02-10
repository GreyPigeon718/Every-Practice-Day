// 最简分数
class Solution {
public:
    int Gcb(int x, int y)
    {
        int a = x;
        int b = y;
        int c;
        while (a % b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        return b;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        for (int i = 2; i <= n; ++i) //代表分母
        {
            for (int j = 1; j < i; ++j) //代表分子
            {
                if (Gcb(i, j) == 1) // 最大公约数
                {
                    v.push_back(to_string(j) + '/' + to_string(i));
                }
            }
        }
        return v;
    }
};

// 存在重复元素II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i;

        }
        return false;
    }
};