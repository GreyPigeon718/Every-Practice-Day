// ÑÕÉ«·ÖÀà
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                int temp = nums[p];
                nums[p] = nums[i];
                nums[i] = temp;
                p++;
            }
        }
        for (int j = p; j < nums.size(); ++j)
        {
            if (nums[j] == 1)
            {
                int temp = nums[p];
                nums[p] = nums[j];
                nums[j] = temp;
                p++;
            }
        }
    }
};