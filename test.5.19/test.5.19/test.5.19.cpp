//> ��С��������ʹ����Ԫ�����

class Solution {
public:
    int minMoves(vector<int>& nums) {
        //> n - 1���� ����1 ==> 1���� ��1
        //> ����ֻ�м�����һ�����������Сֵ
        int res = 0;
        int minNum = *min_element(nums.begin(), nums.end());
        for (int& num : nums)
        {
            res += num - minNum;
        }
        return res;
    }
};

//> �����ƶ�����ʹ����Ԫ����� II
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //> ����
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int midNum = nums[n / 2];
        int res = 0;
        for (int& num : nums)
        {
            res += abs(num - midNum);
        }
        return res;
    }
};


//> ��������������ĳ˻�
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int left = 1, right = 1;
        //> ǰ��ʼ�۳ˣ��е����ˮ��ζ��
        for (int i = 0, j = nums.size() - 1; i < nums.size() && j >= 0; ++i, --j)
        {
            res[i] *= left; res[j] *= right;
            left *= nums[i]; right *= nums[j];
        }
        return res;
    }
};

//> ��ת�ַ����еĵ��� III
class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        //> ģ�������ո񣬾ʹ���һ�����ʽ�������ʼ��ת����¼�±꣬�´�ʹ��
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = ++i;
            }
        }
        reverse(s.begin() + start, s.end());
        return s;
    }
};