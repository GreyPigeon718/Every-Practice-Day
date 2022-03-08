//> 绝对差不超过限制的最长连续子数组

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> mt;
        int left = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            mt.insert(nums[i]);
            while (*mt.rbegin() - *mt.begin() > limit)
            {
                mt.erase(mt.find(nums[left++]));
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};