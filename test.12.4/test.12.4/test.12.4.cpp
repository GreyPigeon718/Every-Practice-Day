// 缺失的第一个正数
class Solution1 {
public:
    int firstMissingPositive1(vector<int>& nums) {
        int n = nums.size();
        // 我们将数组中所有小于等于 0 的数修改为 N+1
        // 如果没有在（1，N）中，那么缺失的第一个正数就是N+1
        for (int& e : nums)
        {
            if (e <= 0)
                e = n + 1;
        }

        // 我们遍历数组中的每一个数 x，它可能已经被打了标记，因此原本对应的数为 |x|。
        // 如果∣x∣∈[1,N]，那么我们给数组中的第 |x| - 1 个位置的数添加一个负号。
        // 如果它已经有负号，（因为会有重复）不需要重复添加。
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        //在遍历完成之后，如果数组中的每一个数都是负数，那么答案是 N+1，否则答案是第一个正数的位置加 1
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
// 数值的整数次方
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
// 栈的压入，弹出序列
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


