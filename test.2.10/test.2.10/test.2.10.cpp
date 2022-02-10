// ������
class Solution {
public:
    int Gcb(int x, int y)
    {
        int a = x;
        int b = y;
        int c;
        while (a % b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        return b;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        for (int i = 2; i <= n; ++i) //�����ĸ
        {
            for (int j = 1; j < i; ++j) //�������
            {
                if (Gcb(i, j) == 1) // ���Լ��
                {
                    v.push_back(to_string(j) + '/' + to_string(i));
                }
            }
        }
        return v;
    }
};

// �����ظ�Ԫ��II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k)
                return true;
            mp[nums[i]] = i;

        }
        return false;
    }
};