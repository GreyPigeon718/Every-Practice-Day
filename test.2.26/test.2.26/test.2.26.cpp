//> ��ͬ·��
class Solution {
public:
    int uniquePaths(int m, int n) {
        //> ������ֻ������������ƶ�
        //> ״̬���� dp[i][j] = dp[i-1][j] + dp[i][j-1]
        //> ��ʼ�� �ڵ�i�к͵�j��ֻ��һ��·��
        //> dp[i][0] = 1 , dp[0][j] = 1;
        //> �߽����m��n��
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //> ��ʼ�����
        for (int i = 0; i < m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j)
        {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        //> ���
        return dp[m - 1][n - 1];
    }
};

//> ������ִ�
class Solution {
public:
    string longestPalindrome(string s) {
        //> dp[i][j] ��ʾ����[i,j]�Ƿ�Ϊ���Ĵ�
        //> ��dp[i][j]Ϊ���Ĵ�ʱ��dp[i+1][j-1]Ҳ�ǻ��Ĵ�
        //> "abba"->"bb"
        //> ״̬���̾��� dp[i][j] = dp[i+1][j-1]
        //> ��ʼ�� �����ַ�һ������С�Ļ����ִ�
        //> dp[i] = false;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxlen = 0;
        int left;
        int right;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < s.size(); ++j)
            {
                //> �������������ȺͲ����
                if (s[i] == s[j])
                {
                    //> ��ȷ��������1.i��j���2.i��j����3.i��j������
                    if (j - i <= 1)
                        dp[i][j] = true;
                    else if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }

                if (j - i + 1 > maxlen && dp[i][j])
                {
                    maxlen = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

//> �Ȳ����л���
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0, cnt = 1;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
                ans += cnt++;
            else
                cnt = 1;
        }
        return ans;
    }
};

//> ����Ԫ��֮�������ֵ
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = -1;
        int element = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > element)
                res = max(nums[i] - element, res);
            else
                element = nums[i];
        }
        return res;
    }
};