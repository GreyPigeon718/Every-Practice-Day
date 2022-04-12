//> 分割等和子集
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //> dp[j] : 容量为j的背包，所背的物品价值可以最大为dp[j]。
        vector<int> dp(10001, 0);
        //> 初始化 ： dp[0] = 0;
        int sum = 0;
        for (int num : nums)
            sum += num;
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        //> 开始01背包
        //> 先遍历物品，在遍历背包
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                //> 状态转移方程 dp[j] = max(dp[j], dp[j - i] + nums[i])
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target)
            return true;
        return false;
    }
};
//> 最后一块石头的重量
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

//> 最后一块石头的重量 II
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //> 01背包问题
        //> dp[j] : 容量为j的背包最大的重量
        vector<int> dp(1501, 0);
        //> 初始化，最大容量就是 30 * 100 / 2 = 1500 初始化为零
        int sum = 0;
        for (int stone : stones)
            sum += stone;
        int target = sum / 2;
        //> 遍历顺序，先石头，后容量
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = target; j >= stones[i]; --j)
            {
                //> 状态转移方程 ：dp[j] = max(dp[j], dp[j - stones[i] + stones[i]]
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];
    }
};
