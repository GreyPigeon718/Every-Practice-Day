// “气球” 的最大数量
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector <int> v(5, 0);
        for (int i = 0; i < text.size(); ++i)
        {
            if (text[i] == 'b')
                v[0]++;
            else if (text[i] == 'a')
                v[1]++;
            else if (text[i] == 'l')
                v[2]++;
            else if (text[i] == 'o')
                v[3]++;
            else if (text[i] == 'n')
                v[4]++;
        }
        v[2] /= 2;
        v[3] /= 2;
        return *min_element(v.begin(), v.end());
    }
};
// 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    int Bin_Lsearch(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int Leftborder = -2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid - 1;
                Leftborder = right;
            }
            else
                left = mid + 1;
        }
        return Leftborder;
    }
    int Bin_Rsearch(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int Rightborder = -2;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right = mid - 1;
            else
            {
                left = mid + 1;
                Rightborder = left;
            }
        }
        return Rightborder;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int Leftborder = Bin_Lsearch(nums, target);
        int Rightborder = Bin_Rsearch(nums, target);
        if (Leftborder == -2 || Rightborder == -2)
            return { -1,-1 };
        if (Rightborder - Leftborder > 1)
            return { Leftborder + 1, Rightborder - 1 };
        return { -1,-1 };
    }
};
// 搜索旋转排序数组
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return  -1;
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0;
        int right = nums.size() - 1;
        while (right >= left)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            else
            {
                if (nums[mid] < target && target <= nums[nums.size() - 1])
                {
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};