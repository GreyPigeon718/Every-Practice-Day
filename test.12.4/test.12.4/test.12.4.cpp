// ȱʧ�ĵ�һ������
class Solution1 {
public:
    int firstMissingPositive1(vector<int>& nums) {
        int n = nums.size();
        // ���ǽ�����������С�ڵ��� 0 �����޸�Ϊ N+1
        // ���û���ڣ�1��N���У���ôȱʧ�ĵ�һ����������N+1
        for (int& e : nums)
        {
            if (e <= 0)
                e = n + 1;
        }

        // ���Ǳ��������е�ÿһ���� x���������Ѿ������˱�ǣ����ԭ����Ӧ����Ϊ |x|��
        // ����Ox�O��[1,N]����ô���Ǹ������еĵ� |x| - 1 ��λ�õ������һ�����š�
        // ������Ѿ��и��ţ�����Ϊ�����ظ�������Ҫ�ظ���ӡ�
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        //�ڱ������֮����������е�ÿһ�������Ǹ�������ô���� N+1��������ǵ�һ��������λ�ü� 1
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
                swap(nums[nums[i] - 1], nums[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// pow(x,y)
class Solution {
public:
    double quickMul(double x, long long N)
    {
        if (N == 0)
        {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// ��ֵ�������η�
class Solution {
public:
    double quickMul(double x, long long N)
    {
        if (N == 0)
            return 1.0;
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// ջ��ѹ�룬��������
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size())
            return false;
        stack<int> st1;
        for (int i = 0, j = 0; i < pushed.size(); ++i)
        {
            st1.push(pushed[i]);
            while (!st1.empty() && st1.top() == popped[j])
            {
                st1.pop();
                ++j;
            }
        }
        return st1.empty();
    }
};


