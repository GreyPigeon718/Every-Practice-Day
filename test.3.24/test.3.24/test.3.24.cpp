//>  ������
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

//> �����ǰ׺
class Solution {
public:
    string shortest(vector<string>& strs)          //Ѱ����̵��ַ���
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
        //> �õ���̵��ַ���
        string s = shortest(strs);
        for (int i = 0; i < s.size(); ++i)
        {
            //> ȡ��strs[index]���ַ�
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


//> ��������ת����
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


//> ������̨������
//������10- II. ������̨������
//��׼����
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

//> ���Ч����
class Solution {
public:
    int longestValidParentheses(string s) {
        //> dp[i]����ǰλ�õ����Ч����
        //> ��ʼ����Ϊ��
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i)
        {
            //> ()
            //> ........))
            //> ״̬ת�Ʒ��̣�dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                //> i - dp[i-1] - i ��δƥ��ģ�Ӧ��ƥ���λ��
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            res = max(dp[i], res);
        }
        return res;
    }
};

//> ����ܺ�
class Solution {
public:
    void backtraveral(vector<int>& candidates, int target, int start, int sum)
    {
        //> �����г�����
        if (sum > target)
            return;
        if (sum == target)
        {
            // ���������ﵽĿ��ֵ
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            //> ��ʼ����
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtraveral(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //> �����ĸ�����   ���� Ŀ��ֵ �ݹ���� ��ǰ��ֵ
        backtraveral(candidates, target, 0, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};

//> ����ܺ� II
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
            //> ��ͬһ�����ͬԪ������
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


//> �ָ���Ĵ�
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
        //> ���ݵ��г��������и��ַ���
        if (index >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            //> �Ƿ�����ַ���
            if (isPalindrome(s, index, i))
            {
                string _s = s.substr(index, i - index + 1);
                path.push_back(_s);
            }
            else
                continue;
            //> ��ʼ���ݣ����õ���pathΪ�գ�else continue����
            backtraversal(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        //> �ַ���  ���ݲ���
        backtraversal(s, 0);
        return res;
    }
private:
    vector<string> path;
    vector<vector<string>> res;
};

//>  ��ԭ IP ��ַ
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



//> �Ӽ�
class Solution {
public:
    void backtraversal(vector<int>& nums, int index)
    {
        //> ȫ���Ӽ�
        res.push_back(path);
        //> ��֦
        if (index >= nums.size())
            return;
        for (int i = index; i < nums.size(); ++i)
        {
            //> ��ʼ����
            path.push_back(nums[i]);
            backtraversal(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        //> ���飬 ���ݲ�������֤Ԫ�ز��ظ���
        backtraversal(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};

//> �Ӽ� II
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




//> ����������
class Solution {
public:
    void backtraversal(vector<int>& nums, int index)
    {
        //> ��������Ԫ��
        if (path.size() >= 2)
            res.push_back(path);
        unordered_set<int> ut;
        for (int i = index; i < nums.size(); ++i)
        {
            //> ͬһ�ڵ��µ�ֵ�����ظ�ʹ��
            if (!path.empty() && nums[i] < path.back() || ut.count(nums[i]) == 1)
                continue;
            //> ����
            ut.insert(nums[i]);
            path.push_back(nums[i]);
            backtraversal(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //> ���� ���ݲ���
        backtraversal(nums, 0);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};


//> ȫ����
class Solution {
public:
    void backtraversal(vector<int>& nums, vector<bool>& used)
    {
        //> �����г�������ȫ���д�С = ԭ��С
        if (nums.size() == path.size())
        {
            res.push_back(path);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] == false)
            {
                // ��ʼ����
                used[i] = true;
                path.push_back(nums[i]);
                backtraversal(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //> ����Ѿ�ѡ�����ֵ
        vector<bool> used(nums.size(), false);
        backtraversal(nums, used);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
};




//> ȫ���� II
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