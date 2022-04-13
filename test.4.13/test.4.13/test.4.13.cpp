//> Ŀ���
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        //> ���У�ͬ�ţ� - ���У�ͬ�ţ� = target => ���� = ���� - target
        //> ���� + ���� = sum => ���� = sum - ����
        //> ���� = (sum + target) /2 
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
        //> dp[j] : ֵΪj������ַ���
        //> ״̬ת�Ʒ��� dp[j] += dp[j - nums[i]];
        //> ��ʼ��״̬ dp[0] == 1 :  ֵΪ���ֻ��һ����������ֻ����
        //> 0 1����
        //> ����Ʒ���󱳰�

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

//> һ����
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //> û�뵽�ɣ�����01����
        //> dp[i][j]�������i��0��j��1��strs������Ӽ��Ĵ�СΪdp[i][j]��
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        //> ��ʼ��״̬: dp(strs.size() + 1, 0);
        for (string str : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (char c : str)
            {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            //> m��n�����ԣ�������m ->  n
            for (int i = m; i >= zeroNum; --i)
            {
                for (int j = n; j >= oneNum; --j)
                {
                    //> ״̬ת�Ʒ��̣�dp[i][j] = max( dp[i][j], dp[i - zeroNum][j - oneNum] + 1)
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

//> O(1) ʱ����롢ɾ���ͻ�ȡ���Ԫ��
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
    vector<int> v; //> �����±�
    unordered_map<int, int> up; //> �±� �� Ԫ��  
};