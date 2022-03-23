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
    string longestCommonPrefix(vector<string>& strs)
    {
        string s = shortest(strs);
        int len1 = s.length();
        int Size = strs.size();
        for (int i = 0; i < len1; i++)              //对第一个字符的所有字符遍历
        {
            char m = s[i];                       //第一个字符串的第一个字符  

            for (int j = 0; j < Size; j++)          //判断从第二个往后，每个字符串是否都有s[i]
            {
                if (strs[j].at(i) != m)           //不含有s[i]
                {
                    if (i == 0)
                        return "";                   //返回空字符串
                    else
                        return s.substr(0, i);        //返回字符串前i位
                }
            }
        }
        return s;
    }
};

//> 买卖股票的最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxpro = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            maxpro = max(prices[i] - minprice, maxpro);
            minprice = min(prices[i], minprice);
        }
        return maxpro;
    }
};

//> 组合
class Solution {
public:
    void backtracking(int n, int index, int k)
    {
        //> 该组合满足k,加入
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        //> 可以减枝
        for (int i = index; i <= n - (k - path.size()) + 1; ++i)
        {
            //> 开始回溯
            path.push_back(i);
            backtracking(n, i + 1, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (k > n)
            return res;
        backtracking(n, 1, k);//> 1 表示第几层回溯
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};


//> 组合总和 III
class Solution {
public:
    void backtarvel(int k, int n, int index, int sum)
    {
        //> 回溯判出条件
        if (path.size() == k)
        {
            if (sum == n)
                res.push_back(path);
            return;
        }
        //> 横向遍历+剪枝
        for (int i = index; i <= 9 - (k - path.size()) + 1; ++i)
        {
            //> 开始回溯
            sum += i;
            path.push_back(i);
            backtarvel(k, n, i + 1, sum);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = n;
        //> k , n, 回溯次数，当前值
        backtarvel(k, n, 1, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};

//> 电话号码的字母组合

class Solution {
public:
    const string smap[10] = { "",
                        "",
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz" };
    void backtricking(string& digits, int x)
    {
        //> 回溯判出条件
        if (digits.size() == x)
        {
            res.push_back(s);
            return;
        }
        int digit = digits[x] - '0';
        string sn = smap[digit];
        //> 横向遍历
        for (int i = 0; i < sn.size(); ++i)
        {
            //> 开始回溯
            s.push_back(sn[i]);
            backtricking(digits, x + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0)
            return res;
        //> 回溯字符，当前字符个数
        backtricking(digits, 0);
        return res;
    }
private:
    vector<string> res;
    string s;
};