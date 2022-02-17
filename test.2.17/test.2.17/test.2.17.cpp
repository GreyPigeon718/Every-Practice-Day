//> 找到字符串中所有字母异位词
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        //> 当s字符串 < p字符串时，就不会有异位词。
        if (s.size() < p.size())
            return res;
        vector<int> s_size(26);
        vector<int> p_size(26);
        for (int i = 0; i < p.size(); ++i)
        {
            ++s_size[s[i] - 'a'];
            ++p_size[p[i] - 'a'];
        }
        //> 如果两个相等，说明两字符刚开始就是异位词
        if (s_size == p_size)
            res.push_back(0);

        //> 滑动窗口
        for (int j = 0; j < s.size() - p.size(); ++j)
        {
            --s_size[s[j] - 'a'];
            ++s_size[s[j + p.size()] - 'a'];
            if (s_size == p_size)
                res.push_back(j + 1);
        }
        return res;
    }
};

//> 乘积小于K的子数组
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        //> dp_1为乘积，dp_2为遍历个数
        int dp_1 = 1, dp_2 = 0, ans = 0, left = 0, right = 0;
        while (right < len) {
            dp_1 *= nums[right++];
            dp_2 += 1;
            //> 当乘积 > k时，滑动窗口向前滑动，同时乘积回过去
            while (left < right && dp_1 >= k) {
                dp_1 /= nums[left++];
                dp_2 -= 1;
            }
            ans += dp_2;
        }
        return ans;
    }
};

//> 长度最小的子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        if (nums.size() == 0)
            return 0;
        int left = 0, right = 0;
        int sum = 0, res = INT_MAX;
        //> 滑动窗口
        while (right < len)
        {
            sum += nums[right];
            while (sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
