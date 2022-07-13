//> 数组中的逆序对
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(0, nums.size() - 1, nums, tmp);
    }
private:
    int mergeSort(int left, int right, vector<int>& nums, vector<int>& tmp)
    {
        if (left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int res = mergeSort(left, mid, nums, tmp) + mergeSort(mid + 1, right, nums, tmp);

        int i = left, j = mid + 1;
        for (int k = left; k <= right; ++k)
            tmp[k] = nums[k];
        for (int k = left; k <= right; ++k)
        {
            if (i == mid + 1)
                nums[k] = tmp[j++];
            else if (j == right + 1 || tmp[i] <= tmp[j])
                nums[k] = tmp[i++];
            else
            {
                nums[k] = tmp[j++];
                res += mid - i + 1;
            }
        }
        return res;
    }
};

