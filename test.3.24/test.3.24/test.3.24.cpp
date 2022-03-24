//>  回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long res = x;
        long sum = 0;
        long y = 0;
        while (x)
        {
            y += x % 10;
            y = y * 10;
            x /= 10;
        }
        y /= 10;
        if (res == y)
            return true;
        return false;
    }
};

//> 最长公共前缀
class Solution {
public:
    string shortest(vector<string>& strs)          //寻找最短的字符串
    {
        int Size = strs.size();
        string temp = strs[0];
        for (int k = 1; k < Size; k++)
        {
            if (strs[k].length() < temp.length())
                temp = strs[k];
        }
        return temp;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        //> 得到最短的字符串
        string s = shortest(strs);
        for (int i = 0; i < s.size(); ++i)
        {
            //> 取出strs[index]的字符
            char ch = s[i];
            for (int j = 0; j < strs.size(); ++j)
            {
                if (ch != strs[j].at(i))
                {
                    if (i == 0)
                        return "";
                    else
                        return s.substr(0, i);
                }
            }

        }
        return s;
    }
};


//> 罗马数字转整数
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> up{ {'I',1}, {'V',5}, {'X',10},{'L',50},{'C',100},{'D',500},{'M', 1000} };
        int res = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            int x = up[s[i]];
            if (i >= 1 && up[s[i - 1]] < x)
            {
                res += x;
                res -= up[s[i - 1]];
                --i;
            }
            else
                res += x;
        }
        return res;
    }
};


//> 青蛙跳台阶问题
//面试题10- II. 青蛙跳台阶问题
//标准做法
class Solution {
public:
    int numWays(int n) {
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < n; ++i)
        {
            a = b; b = c;
            c = (a + b) % 1000000007;
        }
        return b;
    }
};

//> 最长有效括号
class Solution {
public:
    int longestValidParentheses(string s) {
        //> dp[i]：当前位置的最长有效括号
        //> 初始化：为零
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i)
        {
            //> ()
            //> ........))
            //> 状态转移方程：dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                //> i - dp[i-1] - i 与未匹配的）应该匹配的位置
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//> 组合总和
class Solution {
public:
    void backtraveral(vector<int>& candidates, int target, int start, int sum)
    {
        //> 回溯判出条件
        if (sum > target)
            return;
        if (sum == target)
        {
            // 满足条件达到目标值
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            //> 开始回溯
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtraveral(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //> 传递四个参数   数组 目标值 递归层数 当前数值
        backtraveral(candidates, target, 0, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};

//> 组合总和 II
class Solution {
public:
    void backtraversal(vector<int>& candidates, int target, int start, int sum)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && sum + candidates[i] <= target; ++i)
        {
            //> 对同一层的相同元素跳过
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtraversal(candidates, target, i + 1, sum);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtraversal(candidates, target, 0, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};


//> 分割回文串
class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return false;
        }
        return  true;
    }
    void backtraversal(string s, int index)
    {
        //> 回溯的判出条件，切割字符串
        if (index >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            //> 是否回文字符串
            if (isPalindrome(s, index, i))
            {
                string _s = s.substr(index, i - index + 1);
                path.push_back(_s);
            }
            else
                continue;
            //> 开始回溯，不用担心path为空，else continue跳出
            backtraversal(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        //> 字符串  回溯层数
        backtraversal(s, 0);
        return res;
    }
private:
    vector<string> path;
    vector<vector<string>> res;
};

//>  复原 IP 地址
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



//> 子集
class Solution {
public:
    void backtraversal(vector<int>& nums, int index)
    {
        //> 全部子集
        res.push_back(path);
        //> 剪枝
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); ++i)
        {
            //> 开始回溯
            path.push_back(nums[i]);
            backtraversal(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //> 数组， 回溯层数（保证元素不重复）
        backtraversal(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};

//> 子集 II
class Solution {
public:
    void backtraversal(vector<int>& nums, int index)
    {
        res.push_back(path);
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); ++i)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            backtraversal(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtraversal(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};




//> 递增子序列
class Solution {
public:
    void backtraversal(vector<int>& nums, int index)
    {
        //> 至少两个元素
        if (path.size() >= 2)
            res.push_back(path);
        unordered_set<int> ut;
        for (int i = index; i < nums.size(); ++i)
        {
            //> 同一节点下的值不能重复使用
            if (!path.empty() && nums[i] < path.back() || ut.count(nums[i]) == 1)
                continue;
            //> 回溯
            ut.insert(nums[i]);
            path.push_back(nums[i]);
            backtraversal(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //> 数组 回溯层数
        backtraversal(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};


//> 全排列
class Solution {
public:
    void backtraversal(vector<int>& nums, vector<bool>& used)
    {
        //> 回溯判出条件：全排列大小 = 原大小
        if (nums.size() == path.size())
        {
            res.push_back(path);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == false)
            {
                // 开始回溯
                used[i] = true;
                path.push_back(nums[i]);
                backtraversal(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //> 标记已经选择过的值
        vector<bool> used(nums.size(), false);
        backtraversal(nums, used);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};




//> 全排列 II
class Solution {
public:
    void backtrasversal(vector<int>& nums, vector<bool>& used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (!used[i])
            {
                used[i] = true;
                path.push_back(nums[i]);
                backtrasversal(nums, used);
                used[i] = false;
                path.pop_back();
            }


        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrasversal(nums, used);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};