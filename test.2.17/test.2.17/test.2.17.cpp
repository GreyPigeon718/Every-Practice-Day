//> �ҵ��ַ�����������ĸ��λ��
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        //> ��s�ַ��� < p�ַ���ʱ���Ͳ�������λ�ʡ�
        if (s.size() < p.size())
            return res;
        vector<int> s_size(26);
        vector<int> p_size(26);
        for (int i = 0; i < p.size(); ++i)
        {
            ++s_size[s[i] - 'a'];
            ++p_size[p[i] - 'a'];
        }
        //> ���������ȣ�˵�����ַ��տ�ʼ������λ��
        if (s_size == p_size)
            res.push_back(0);

        //> ��������
        for (int j = 0; j < s.size() - p.size(); ++j)
        {
            --s_size[s[j] - 'a'];
            ++s_size[s[j + p.size()] - 'a'];
            if (s_size == p_size)
                res.push_back(j + 1);
        }
        return res;
    }
};

//> �˻�С��K��������
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int len = nums.size();
        //> dp_1Ϊ�˻���dp_2Ϊ��������
        int dp_1 = 1, dp_2 = 0, ans = 0, left = 0, right = 0;
        while (right < len) {
            dp_1 *= nums[right++];
            dp_2 += 1;
            //> ���˻� > kʱ������������ǰ������ͬʱ�˻��ع�ȥ
            while (left < right && dp_1 >= k) {
                dp_1 /= nums[left++];
                dp_2 -= 1;
            }
            ans += dp_2;
        }
        return ans;
    }
};

//> ������С��������
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        if (nums.size() == 0)
            return 0;
        int left = 0, right = 0;
        int sum = 0, res = INT_MAX;
        //> ��������
        while (right < len)
        {
            sum += nums[right];
            while (sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
