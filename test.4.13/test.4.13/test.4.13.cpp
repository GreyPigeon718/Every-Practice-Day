//> 目标和
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        //> 左列（同号） - 右列（同号） = target => 右列 = 右列 - target
        //> 左列 + 右列 = sum => 左列 = sum - 右列
        //> 左列 = (sum + target) /2 
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }
        if ((sum + target) % 2 == 1)
            return 0;
        if (abs(target) > sum)
            return 0;
        int size = (sum + target) / 2;
        //> dp[j] : 值为j的最多种方法
        //> 状态转移方程 dp[j] += dp[j - nums[i]];
        //> 初始化状态 dp[0] == 1 :  值为零就只有一个方法，就只有零
        //> 0 1背包
        //> 先物品，后背包

        vector<int> dp(10001, 0);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = size; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[size];
    }
};

//> 一和零
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //> 没想到吧！还是01背包
        //> dp[i][j]：最多有i个0和j个1的strs的最大子集的大小为dp[i][j]。
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //> 初始化状态: dp(strs.size() + 1, 0);
        for (string str : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (char c : str)
            {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            //> m和n都可以，这里我m ->  n
            for (int i = m; i >= zeroNum; --i)
            {
                for (int j = n; j >= oneNum; --j)
                {
                    //> 状态转移方程：dp[i][j] = max( dp[i][j], dp[i - zeroNum][j - oneNum] + 1)
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

//> O(1) 时间插入、删除和获取随机元素
class RandomizedSet {
public:
    RandomizedSet() { srand((unsigned)time(NULL)); }

    bool insert(int val) {
        if (up.count(val))
        {
            return false;
        }
        int index = v.size();
        v.emplace_back(val);
        up[val] = index;
        return true;
    }

    bool remove(int val) {
        if (!up.count(val))
        {
            return false;
        }
        int index = up[val];
        int last = v.back();
        v[index] = last;
        up[last] = index;
        up.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom() {
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
private:
    vector<int> v; //> 代表下标
    unordered_map<int, int> up; //> 下标 和 元素  
};