// ���������
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> num;
        sort(nums.begin(), nums.end());
        int res = 1;
        for (int i = 0; i < n; i++) {//ȥ���ظ�Ԫ��
            while (i < n - 1 && nums[i + 1] == nums[i])
                i++;
            num.push_back(nums[i]);
        }
        n = num.size();
        for (int i = 0; i < n - 1; i++) {
            int a = 1;//��¼�������ֵĸ���
            if (num[i + 1] - num[i] == 1) {
                while (i < n - 1 && num[i + 1] - num[i] == 1) {
                    a++;
                    i++;
                }
            }
            res = max(a, res);//��¼ÿһ���������ֳ��ȵ����ֵ
        }
        return res;
    }
};
