//> �ָ�Ⱥ��Ӽ�
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //> dp[j] : ����Ϊj�ı�������������Ʒ��ֵ�������Ϊdp[j]��
        vector<int> dp(10001, 0);
        //> ��ʼ�� �� dp[0] = 0;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        //> ��ʼ01����
        //> �ȱ�����Ʒ���ڱ�������
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                //> ״̬ת�Ʒ��� dp[j] = max(dp[j], dp[j - i] + nums[i])
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
            return true;
        return false;
    }
};
//> ���һ��ʯͷ������
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pqe;
        for (int stone : stones)
            pqe.push(stone);

        while (pqe.size() > 1)
        {
            int x = pqe.top();
            pqe.pop();
            int y = pqe.top();
            pqe.pop();

            if (x == y)
                continue;
            pqe.push(x - y);
        }
        return pqe.empty() ? 0 : pqe.top();
    }
};

//> ���һ��ʯͷ������ II
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //> 01��������
        //> dp[j] : ����Ϊj�ı�����������
        vector<int> dp(1501, 0);
        //> ��ʼ��������������� 30 * 100 / 2 = 1500 ��ʼ��Ϊ��
        int sum = 0;
        for (int stone : stones)
            sum += stone;
        int target = sum / 2;
        //> ����˳����ʯͷ��������
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                //> ״̬ת�Ʒ��� ��dp[j] = max(dp[j], dp[j - stones[i] + stones[i]]
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};
