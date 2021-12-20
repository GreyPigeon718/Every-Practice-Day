//数组中数字出现的次数 II
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitnum(32, 0);
        for (int num : nums)
        {
            int k = 0;
            while (num)
            {
                bitnum[k++] += num % 2;
                num /= 2;  // 十进制转换为二进制
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            res += (1 << i) * (bitnum[i] % 3); //   二进制转换为十进制
        }
        return res;
    }
};