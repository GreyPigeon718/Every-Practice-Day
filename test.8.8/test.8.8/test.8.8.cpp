
//> 分发饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie = 0;
        int children = 0;
        while (cookie < s.size() && children < g.size())
        {
            if (s[cookie] >= g[children])
                ++children;
            ++cookie;
        }
        return children;
    }
};

//> 分发糖果
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size < 2)
            return size;

        vector<int> nums(size, 1);
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i - 1])
                nums[i] = nums[i - 1] + 1;
        }

        for (int i = size - 1; i > 0; --i)
        {
            if (ratings[i - 1] > ratings[i])
                nums[i - 1] = max(nums[i] + 1, nums[i - 1]);
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};


//> 无重叠区间
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b)
            {return a[1] < b[1]; });

        int size = intervals.size();
        int pre = intervals[0][1];
        int minNum = 0;
        for (int i = 1; i < size; ++i)
        {
            if (intervals[i][0] < pre)
                minNum++;
            else
                pre = intervals[i][1];
        }
        return minNum;
    }
};