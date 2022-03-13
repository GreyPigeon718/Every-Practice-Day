//> 整数除法
class Solution {
public:
    int divide(int dividend, int divisor) {
        //为了避免被除数为0x80000000（即INT_MIN），除数为-1时，商为INT_MAX+1，会造成整形溢出
        //因为最小的整数是-2^32，而最大的整数是2^31 - 1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        //利用异或运算符，两个数如果同号则结果为正数，异号则结果为负数
        int flag = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        if (dividend > 0) dividend = -dividend; //统一转换为负数
        if (divisor > 0) divisor = -divisor;

        unsigned res = divideCode(dividend, divisor);
        return flag == 1 ? res : -res;
    }

    int divideCode(int dividend, int divisor)
    {
        int res = 0;

        //当被除数大于除数时一直循环，注意此时两个数都是负数，所以越小即是越大
        while (dividend <= divisor)
        {
            int value = divisor;        //存一下当前循环的除数
            unsigned quotient = 1;      //quotient:商

            //0xc0000000表示INT_MIN的一半
            while (value >= 0xc0000000 && dividend <= value + value)
            {
                quotient += quotient;   //除数与商每次循环加倍
                value += value;
            }

            res += quotient;            //更新结果与被除数的值
            dividend -= value;
        }

        return res;
    }
};

//> 用栈实现队列
class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty())
            fun();
        int x = st2.top();
        st2.pop();
        return x;
    }

    int peek() {
        if (st2.empty())
            fun();
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;

    void fun()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


//> 比较版本号
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size();
        int len2 = version2.size();
        int p = 0, q = 0;
        while (p < len1 || q < len2)
        {
            int x = 0;
            while (p < len1 && version1[p] != '.')
            {
                x = x * 10 + (version1[p] - '0');
                p++;
            }
            int y = 0;
            while (q < len2 && version2[q] != '.')
            {
                y = y * 10 + (version2[q] - '0');
                q++;
            }
            if (x < y)
                return -1;
            else if (x > y)
                return 1;
            p++;
            q++;
        }
        return 0;
    }
};

//> 复原IP地址
class Solution {
public:
    bool isValid(string s, int start, int end)
    {
        if (start > end)
            return false;
        //> 不能0开头
        //> 不能是超过255
        //> 不能是非法字符
        if (start != end && s[start] == '0')
            return false;
        int num = 0;
        for (int i = start; i <= end; ++i)
        {
            if (s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255)
                return false;
        }
        return true;
    }
    void backstack(string& s, int start, int pointNum)
    {
        //> s字符数组，start开始位置，pointNum'.'的个数，也就是几段
        //> 如果四段了，判断第四段是否合法，然后结束
        if (pointNum == 3)
        {
            if (isValid(s, start, s.size() - 1))
                result.push_back(s);
            else
                return;
        }
        for (int i = start; i < s.size(); ++i)
        {
            if (isValid(s, start, i))
            {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backstack(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() > 12)
            return result;
        backstack(s, 0, 0);
        return result;
    }
private:
    vector<string> result;
};