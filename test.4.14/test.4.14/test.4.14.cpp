//> ��пͻ����ʲ�����
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_money = 0;
        for (int i = 0; i < accounts.size(); ++i)
        {
            int money_num = 0;
            for (int j = 0; j < accounts[0].size(); ++j)
            {
                money_num += accounts[i][j];
            }
            if (money_num > max_money)
                max_money = money_num;
        }
        return max_money;
    }
};
//> ��Ǯ�һ� II
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //> 01����
        //> dp[j] : ��ʾ�ܽ��Ϊj�����
        vector<int> dp(amount + 1, 0);

        //> dp[0] = 1;
        dp[0] = 1;

        //> ����˳���Ƚ����Ӳ��
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                //> ״̬ת�Ʒ��̣�dp[j] += dp[j - coins[i]];
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};

//> ����ܺ� ��
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        //> 01����
        //> dp[j]: �ܺ�Ϊj����ϸ���
        vector<int> dp(target + 1, 0);

        //> ��ʼ���� dp[0] = 1;
        dp[0] = 1;

        //> ����˳���ȱ�����num
        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                //> C++������������������ӳ���int�����ݣ�������Ҫ��if�����dp[i] < INT_MAX - dp[i - num]��
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]])
                {
                    //> ״̬ת�Ʒ��̣�dp[i] += dp[i - nums[j]]
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
