// 寻找峰值

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        // 一直保证[left, right]有解
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid和mid+1进行比较，会判断爬坡的方向
            // 如果mid+1大，说明峰在后面
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            // mid大，峰在前面
            else
                right = mid;
        }
        // 退出条件就是left == right的时候，[left, right]有峰，峰就是right
        return right;
    }
};