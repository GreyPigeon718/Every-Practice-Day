
//> ������Ʊ�����ʱ����������
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //> dp[i][0] ��ʾ��i����й�Ʊ��ʡ����ֽ� 
        //> dp[i][1] ��ʾ��i�첻���й�Ʊ��������ֽ�
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        //> ����˳�� ��->��
        for (int i = 1; i < prices.size(); ++i)
        {
            //> ״̬ת�Ʒ��̣�dp[i][0] = max(dp[i-1][0], dp[i - 1][1] + prices[i]);
        //> ״̬ת�Ʒ��̣�dp[i][1] = max(dp[i-1][1], dp[i - 1][0] + prices[i] - fee);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][0]);
    }
};


//> �����������
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
                //> ״̬ת�Ʒ��� dp[i] = max (dp[j]+1,dp[i]);
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//> �������������
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxlengrh = 0;
        while (right < nums.size())
        {
            if (right > 0 && nums[right] <= nums[right - 1])
            {
                left = right;
            }
            maxlengrh = max(right - left + 1, maxlengrh);
            right++;
        }
        return maxlengrh;
    }
};

