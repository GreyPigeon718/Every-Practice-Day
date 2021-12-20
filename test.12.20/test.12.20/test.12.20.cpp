//���������ֳ��ֵĴ��� II
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
                num /= 2;  // ʮ����ת��Ϊ������
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            res += (1 << i) * (bitnum[i] % 3); //   ������ת��Ϊʮ����
        }
        return res;
    }
};