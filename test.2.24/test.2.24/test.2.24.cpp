//> 打家劫舍 II
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        int first = nums[start];
        //> 刚开始的时候，相当于两个房子，选个大的
        int second = max(nums[start], nums[start + 1]);
        //> 从第三个开始不能相邻
        for (int i = start + 2; i <= end; ++i)
        {
            int temp = second;
            // 不偷和偷的钱作比较
            second = max(second, nums[i] + first);
            first = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        //> 只有一个房间
        if (nums.size() == 1)
            return nums[0];
        //> 只有两个房间
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        // 因为相邻的房间取不到，所有需要两次，遍历完全部
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};

class Solution1 {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        }
        else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};
//> 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
                return false;
            //> k表示可以调到最远的位置
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
