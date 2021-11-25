//有效的括号
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> m{ {'(',1},{'[',2},{'{',3},
                                {')',4},{']',5},{'}',6} };
        stack<char> st;
        bool istrue = true;
        for (char c : s) {
            int flag = m[c];
            if (flag >= 1 && flag <= 3) st.push(c);
            else if (!st.empty() && m[st.top()] == flag - 3) st.pop();
            else { istrue = false; break; }
        }
        if (!st.empty()) istrue = false;
        return istrue;
    }
};
// 最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 二维vector初始化
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // text1遍历
        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                // 从三个方向进行递推
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
// 全排列
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    void tarck(vector<int>& nums, vector<bool> used)
    {
        if (v.size() == nums.size())
        {
            vv.push_back(v);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == true)
                continue;
            used[i] = true;
            v.push_back(nums[i]);
            tarck(nums, used);
            v.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //vv.clear();
        //v.clear();
        vector<bool> u(nums.size(), false);
        tarck(nums, u);
        return vv;
    }
};
//把数组排成最小的数
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector <string> ss;
        string s;
        for (int e : nums)
            ss.push_back(to_string(e));
        sort(ss.begin(), ss.end(), [](string& x, string& y) {  return x + y < y + x; });
        for (string a : ss)
            s.append(a);
        return s;
    }
};
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector <string> ss;
        string s;
        for (int e : nums)
            ss.push_back(to_string(e));
        Quick(ss, 0, ss.size() - 1);
        //sort(ss.begin(), ss.end(),[](string &x, string &y){  return x + y < y + x;});
        for (string a : ss)
            s.append(a);
        return s;
    }
private:
    void Quick(vector<string>& ss, int left, int right)
    {
        if (left >= right)
            return;
        int begin = left;
        int end = right;
        while (begin < end)
        {
            while (ss[end] + ss[left] >= ss[left] + ss[end] && begin < end)
                --end;
            while (ss[begin] + ss[left] <= ss[left] + ss[begin] && begin < end)
                ++begin;

            swap(ss[begin], ss[end]);
        }
        swap(ss[begin], ss[left]);
        Quick(ss, left, begin - 1);
        Quick(ss, begin + 1, right);
    }
};