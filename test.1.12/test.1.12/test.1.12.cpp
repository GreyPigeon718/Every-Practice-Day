// 最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> num;
        sort(nums.begin(), nums.end());
        int res = 1;
        for (int i = 0; i < n; i++) {//去掉重复元素
            while (i < n - 1 && nums[i + 1] == nums[i])
                i++;
            num.push_back(nums[i]);
        }
        n = num.size();
        for (int i = 0; i < n - 1; i++) {
            int a = 1;//记录连续数字的个数
            if (num[i + 1] - num[i] == 1) {
                while (i < n - 1 && num[i + 1] - num[i] == 1) {
                    a++;
                    i++;
                }
            }
            res = max(a, res);//记录每一段连续数字长度的最大值
        }
        return res;
    }
};
