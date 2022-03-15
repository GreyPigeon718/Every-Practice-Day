//> �����������ֵ
class Solution {
private:
    class MyQueue // �������� (�Ӵ�С)
    {
    public:
        //> ÿ��pop��ʱ�������������Ԫ�غͶ��пڵ�Ԫ����ȣ��򵯳�
        //> ˵���Ѿ������������ֵ���ڵĻ������ڣ�Ҳ����˵����λ���ɾ����Ԫ��Ϊ��ֵ
        //> ͬʱҪ�Զ��н����п�
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
                que.pop_front();
        }
        //> ���push����ֵ���ڶ������Ԫ�ص���ֵ����ô�ͽ����к�˵���ֵ������ֱ��push����ֵС�ڵ��ڶ������Ԫ�ص���ֵΪֹ
        //> ��������֤�������У��Ӵ�С
        void push(int value)
        {
            while (!que.empty() && que.back() < value)
                que.pop_back();
            que.push_back(value);
        }
        //> ���б�����ǵ������У��Ӵ�С
        //> ����ȡ�������ڵ����ֵ��Ҳ���Ƕ��пڵ�Ԫ��
        int front()
        {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue MQ;
        vector<int> v;
        for (int i = 0; i < k; ++i)
        {
            MQ.push(nums[i]);
        }
        v.push_back(MQ.front());
        for (int i = k; i < nums.size(); ++i)
        {
            MQ.pop(nums[i - k]);//���������ƶ�,��-
            MQ.push(nums[i]);  // ����Ԫ�أ���+
            v.push_back(MQ.front()); // ������ֵ
        }
        return v;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> v;
//         int i = 0;
//         while (i <= (nums.size() - k))
//         {
//             v.push_back(*max_element(nums.begin() + i, nums.begin() + k + i));
//             ++i;
//         }
//         return v;
//     }   
// };

//> ��Ч����ĸ��λ��
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};


//> ��������Ľ���
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ut;
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i)
        {
            ut.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (ut.count(nums2[i]))
                result.push_back(nums2[i]);
        }
        unordered_set<int> ut2(result.begin(), result.end());
        return vector<int>(ut2.begin(), ut2.end());
    }
};

//> �ö���ʵ��ջ
class MyStack {
public:
    MyStack() {
    }

    void push(int x) {
        de.push_back(x);
    }

    int pop() {
        if (!de.empty())
        {
            int x = de.back();
            de.pop_back();
            return x;
        }
        return NULL;
    }

    int top() {
        if (!de.empty())
            return de.back();
        return NULL;
    }

    bool empty() {
        return de.empty();
    }
private:
    deque<int> de;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//> �沨�����ʽ��ֵ
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //> �ĸ�����������ǿ���ģ��ʵ��
        stack<int> sk;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                //> �����������ǰ�涨�������������֣���Ԫ������
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();
                //> ����Ľ��������push��ȥ��������һ�ֲ������е�ݹ�
                if (tokens[i] == "+") sk.push(num2 + num1);
                if (tokens[i] == "-") sk.push(num2 - num1);
                if (tokens[i] == "*") sk.push(num2 * num1);
                if (tokens[i] == "/") sk.push(num2 / num1);
            }
            else
            {
                sk.push(stoi(tokens[i]));
            }
        }
        return sk.top();
    }
};