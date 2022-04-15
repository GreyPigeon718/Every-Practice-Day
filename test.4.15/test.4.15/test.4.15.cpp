//> �����﷨������
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int index = 0;
    NestedInteger deserialize(string s) {
        //> ���������
        //> 1.���б�
        //> 2.����
        if (s[index] == '[')
        {
            index++;
            NestedInteger ni;
            while (s[index] != ']')
            {
                ni.add(deserialize(s));
                if (s[index] == ',')
                    index++;
            }
            index++;
            return ni;
        }
        else
        {
            bool symbol = false;
            if (s[index] == '-')
            {
                symbol = true;
                index++;
            }
            int num = 0;
            while (index < s.size() && isdigit(s[index]))
            {
                num = num * 10 + s[index] - '0';
                index++;
            }
            if (symbol)
                num *= -1;
            return NestedInteger(num);
        }
    }
};

//> ��ȫƽ����
class Solution {
public:
    int numSquares(int n) {

        //> ��������
        //> dp[j]: ��Ϊj����ȫƽ��������������
        vector<int> dp(n + 1, INT_MAX);
        //> ��ʼ�� dp[0] = 0;
        dp[0] = 0;
        //> ����˳�� ����� ������Ʒ�󱳰�
        for (int i = 1; i * i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j - i * i >= 0)
                {
                    //> ״̬ת�Ʒ��̣�dp[j] = min(dp[j - i * i] + 1�� dp[j]);
                    dp[j] = min(dp[j - i * i] + 1, dp[j]);
                }
            }
        }
        return dp[n];
    }
};