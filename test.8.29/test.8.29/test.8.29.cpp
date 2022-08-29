//> 重新安排行程
class Solution {
public:
    bool backtraversal(int num, vector<string>& res)
    {
        if (res.size() == num + 1)
        {
            return true;
        }

        for (pair<const string, int>& v : umpp[res[res.size() - 1]])
        {
            if (v.second > 0)  // 记录到达机场是否飞过了
            {
                res.emplace_back(v.first);
                v.second--;
                if (backtraversal(num, res))
                    return true;
                res.pop_back();
                v.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        for (const vector<string>& v : tickets)
        {
            umpp[v[0]][v[1]]++;
        }
        res.emplace_back("JFK");
        backtraversal(tickets.size(), res);
        return res;
    }
private:
    // 航班出发地  降落地   降落地次数
    unordered_map<string, map<string, int>> umpp;
};

//  任务调度器
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();
        vector<int> v(26);
        for (char c : tasks)
            ++v[c - 'A'];
        sort(v.begin(), v.end(), greater<>());
        int cnt = 1;
        while (cnt < v.size() && v[cnt] == v[0])
            cnt++;
        return max(len, cnt + (n + 1) * (v[0] - 1));
    }
};

//> 每日温度
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            // 维护一个单调栈，从栈底到栈顶元素依次增大
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int pre = s.top();
                ans[pre] = i - pre;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};