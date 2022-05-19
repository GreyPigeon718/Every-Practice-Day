//> 最小操作次数使数组元素相等

class Solution {
public:
    int minMoves(vector<int>& nums) {
        //> n - 1个数 增加1 ==> 1个数 减1
        //> 所以只有减法，一定都会减到最小值
        int res = 0;
        int minNum = *min_element(nums.begin(), nums.end());
        for (int& num : nums)
        {
            res += num - minNum;
        }
        return res;
    }
};

//> 最少移动次数使数组元素相等 II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //> 排序
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int midNum = nums[n / 2];
        int res = 0;
        for (int& num : nums)
        {
            res += abs(num - midNum);
        }
        return res;
    }
};


//> 除自身以外数组的乘积
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int left = 1, right = 1;
        //> 前后开始累乘，有点接雨水的味道
        for (int i = 0, j = nums.size() - 1; i < nums.size() && j >= 0; ++i, --j)
        {
            res[i] *= left; res[j] *= right;
            left *= nums[i]; right *= nums[j];
        }
        return res;
    }
};

//> 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        //> 模拟遇到空格，就代表一个单词结束，开始反转，记录下标，下次使用
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = ++i;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};