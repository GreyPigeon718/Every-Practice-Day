//> ��������
class Solution {
public:
    int divide(int dividend, int divisor) {
        //Ϊ�˱��ⱻ����Ϊ0x80000000����INT_MIN��������Ϊ-1ʱ����ΪINT_MAX+1��������������
        //��Ϊ��С��������-2^32��������������2^31 - 1
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        //�����������������������ͬ������Ϊ�������������Ϊ����
        int flag = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        if (dividend > 0) dividend = -dividend; //ͳһת��Ϊ����
        if (divisor > 0) divisor = -divisor;

        unsigned res = divideCode(dividend, divisor);
        return flag == 1 ? res : -res;
    }

    int divideCode(int dividend, int divisor)
    {
        int res = 0;

        //�����������ڳ���ʱһֱѭ����ע���ʱ���������Ǹ���������ԽС����Խ��
        while (dividend <= divisor)
        {
            int value = divisor;        //��һ�µ�ǰѭ���ĳ���
            unsigned quotient = 1;      //quotient:��

            //0xc0000000��ʾINT_MIN��һ��
            while (value >= 0xc0000000 && dividend <= value + value)
            {
                quotient += quotient;   //��������ÿ��ѭ���ӱ�
                value += value;
            }

            res += quotient;            //���½���뱻������ֵ
            dividend -= value;
        }

        return res;
    }
};

//> ��ջʵ�ֶ���
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


//> �Ƚϰ汾��
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

//> ��ԭIP��ַ
class Solution {
public:
    bool isValid(string s, int start, int end)
    {
        if (start > end)
            return false;
        //> ����0��ͷ
        //> �����ǳ���255
        //> �����ǷǷ��ַ�
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
        //> s�ַ����飬start��ʼλ�ã�pointNum'.'�ĸ�����Ҳ���Ǽ���
        //> ����Ķ��ˣ��жϵ��Ķ��Ƿ�Ϸ���Ȼ�����
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