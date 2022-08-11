//> 搜索旋转排序数组 II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[start] == nums[mid]) {
                // 无法判断哪个区间是增序的
                ++start;
            }
            else if (nums[mid] <= nums[end]) {
                // 右区间是增序的
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
            else {
                // 左区间是增序的
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        return false;
    }
};