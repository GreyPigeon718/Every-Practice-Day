//> �ڶ�����
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //> ��ǰ��ֵ
        int curdis = 0;
        //> ��һ�εķ�ֵ
        int predis = 0;
        int res = 1;
        //>  2 2 5������ͬ��ֵ
        for (int i = 1; i < nums.size(); ++i)
        {
            curdis = nums[i] - nums[i - 1];
            //> ��ֵ�Ĳ����
            if ((predis >= 0 && curdis < 0) || (predis <= 0 && curdis > 0))
            {
                res++;
                predis = curdis;
            }
        }
        return res;
    }
};

//>  dp�ⷨ
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return 1;
        //> dp[i][0]: ��ʾ��i������Ϊɽ�����ڶ�����
        //> dp[i][1]: ��ʾ��i������Ϊɽ�ȵ���ڶ�����
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        //> ��ʼ����dp[0][0] = dp[1][0] = 1
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i][0] = dp[i][1] = 1;

            for (int j = 0; j < i; ++j)
            {
                //> Ϊɽ��
                if (nums[j] > nums[i])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
            }
            for (int j = 0; j < i; ++j)
            {
                //> Ϊɽ��
                if (nums[j] < nums[i])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};