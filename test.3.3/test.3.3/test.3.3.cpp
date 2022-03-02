//> ���ʲ��
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //> ��������
        for (int i = 1; i <= s.size(); ++i)
        {
            //> ������Ʒ
            for (int j = 0; j < i; ++j)
            {
                //> �ַ�����ȡ
                string s1 = s.substr(j, i - j);
                //> ��st�ҵ���Ӯ����
                if (st.find(s1) != st.end() && dp[j])
                    dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};


//>  �����������
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //> ÿһ���������ַ����ǵ���������
        vector<int> dp(nums.size(), 1);
        int res = 0;

        //> ����˳���ǰ����
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                //> dp[i] ��ʾi֮ǰ����������г���
                //> ״̬���̾�β dp[i] = max (dp[j + 1],dp[i]);
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//>  ����������еĸ���
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //> 300��һ��,������Ҫ��������
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int Max_Count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }

        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (dp[i] == *max_element(dp.begin(), dp.end()))
                res += count[i];
        }
        return res;
    }
};
