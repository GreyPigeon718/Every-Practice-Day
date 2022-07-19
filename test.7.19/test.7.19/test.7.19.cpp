//> 和为s的两个数字
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] + nums[j] < target)
                ++i;
            else if (nums[i] + nums[j] > target)
                --j;
            else
                return { nums[i], nums[j] };
        }
        return {};
    }
};

//> 和为s的连续正数序列
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i = 1, j = 2, s = 3;
        vector<vector<int>> res;
        while (i < j)
        {
            if (s == target)
            {
                vector<int> ans;
                for (int k = i; k <= j; ++k)
                    ans.emplace_back(k);
                res.emplace_back(ans);
            }
            if (s >= target)
            {
                s -= i;
                ++i;
            }
            else
            {
                ++j;
                s += j;
            }
        }
        return res;
    }
};


