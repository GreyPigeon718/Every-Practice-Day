class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
        {
            if (nums[0] == 1)
                return { 2,3 };
            else if (nums[0] == 2)
                return { 1,3 };
            else
                return { 1,2 };
        }
        int x = 0, y = 0;
        bool flag = true;
        if (nums[0] != 1)
        {
            x = 1;
            flag = false;
        }

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - nums[i - 1] == 2 && flag == true)
            {
                x = nums[i - 1] + 1;
                flag = false;
            }
            else if (nums[i] - nums[i - 1] == 3)
            {
                x = nums[i - 1] + 1;
                y = nums[i] - 1;
            }
            else if (nums[i] - nums[i - 1] == 2 && flag == false)
            {
                y = nums[i - 1] + 1;
            }
        }
        if (y == 0)
            y = nums[nums.size() - 1] + 1;
        return { x,y };
    }
};