//> 滑动窗口最大值
class Solution {
private:
    class MyQueue // 单调队列 (从大到小)
    {
    public:
        //> 每次pop的时候，如果遍历到的元素和队列口的元素相等，则弹出
        //> 说明已经遍历到该最大值不在的滑动窗口，也就是说，这次滑动删除的元素为该值
        //> 同时要对队列进行判空
        deque<int> que;
        void pop(int value)
        {
            if (!que.empty() && que.front() == value)
                que.pop_front();
        }
        //> 如果push的数值大于队列入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止
        //> 这样来保证单调队列，从大到小
        void push(int value)
        {
            while (!que.empty() && que.back() < value)
                que.pop_back();
            que.push_back(value);
        }
        //> 队列本身就是单调队列，从大到小
        //> 所有取滑动窗口的最大值，也就是队列口的元素
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
            MQ.pop(nums[i - k]);//滑动窗口移动,左-
            MQ.push(nums[i]);  // 加入元素，右+
            v.push_back(MQ.front()); // 添加最大值
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

//> 有效的字母异位词
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


//> 两个数组的交集
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

//> 用队列实现栈
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

//> 逆波兰表达式求值
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //> 四个运算符，我们可以模拟实现
        stack<int> sk;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                //> 遇到运算符，前面定有至少两个数字，二元操作符
                int num1 = sk.top();
                sk.pop();
                int num2 = sk.top();
                sk.pop();
                //> 算出的结果，我们push进去，进行下一轮操作，有点递归
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