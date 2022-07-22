//> ��ֵ1Ԫ��4Ԫ��16Ԫ��64Ԫ����4��Ӳ�ң��Լ���ֵ1024Ԫ��ֽ�ҡ�����СYʹ��1024Ԫ��ֽ�ҹ�����һ����ֵΪN(0 < N��1024)����Ʒ���������������յ�����Ӳ��

class Solution {
public:
    /**
     *
     * @param N int����
     * @return int����
     */
    int GetCoinCount(int N) {
        // write code here
        N = 1024 - N;
        int a, b, c, d;
        a = N / 64;
        b = N % 64 / 16;
        c = N % 64 % 16 / 4;
        d = N % 64 % 16 % 4;
        return a + b + c + d;
    }
};


//> ����ƥ��
class Solution {
public:
    /**
     *
     * @param s string�ַ���
     * @return bool������
     */
    bool IsValidExp(string s) {
        // write code here
        stack<int> sk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                sk.push(')');
            else if (s[i] == '{')
                sk.push('}');
            else if (s[i] == '[')
                sk.push(']');
            else if (sk.empty() || sk.top() != s[i])
                return false;
            else
                sk.pop();
        }
        return sk.empty();
    }
};



//> 24��
class Solution {
public:
    /**
     *
     * @param arr int����һά����
     * @param arrLen int arr���鳤��
     * @return bool������
     */
    bool dfs(int index, int result, vector<int> res)
    {
        if (result == 24 && index == 4)
        {
            return true;
        }
        if (index >= 4)
            return false;
        for (int choose = 0; choose < 4; choose++)
        {
            switch (choose)
            {
            case 0:
                dfs(index + 1, result + res[index], res);
                break;
            case 1:
                dfs(index + 1, result - res[index], res);
                break;
            case 2:
                dfs(index + 1, result * res[index], res);
                break;
            case 3:
                dfs(index + 1, result / res[index], res);
                break;
            }
        }
        return false;
    }
    bool Game24Points(int* arr, int arrLen) {
        // write code here
        for (int i = 0; i < arrLen; ++i)
        {
            res.emplace_back(*arr + i);
        }
        sort(res.begin(), res.end());
        return dfs(0, 0, res);
    }
private:
    vector<int> res;
};





//> ���е����ֵ
class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {
    }

    int max_value() {
        if (d.empty())
            return -1;
        return d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty())
            return -1;
        int ans = q.front();
        if (ans == d.front()) {
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};
