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
    string longestCommonPrefix(vector<string>& strs)
    {
        string s = shortest(strs);
        int len1 = s.length();
        int Size = strs.size();
        for (int i = 0; i < len1; i++)              //�Ե�һ���ַ��������ַ�����
        {
            char m = s[i];                       //��һ���ַ����ĵ�һ���ַ�  

            for (int j = 0; j < Size; j++)          //�жϴӵڶ�������ÿ���ַ����Ƿ���s[i]
            {
                if (strs[j].at(i) != m)           //������s[i]
                {
                    if (i == 0)
                        return "";                   //���ؿ��ַ���
                    else
                        return s.substr(0, i);        //�����ַ���ǰiλ
                }
            }
        }
        return s;
    }
};

//> ������Ʊ�����ʱ��
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

//> ���
class Solution {
public:
    void backtracking(int n, int index, int k)
    {
        //> ���������k,����
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        //> ���Լ�֦
        for (int i = index; i <= n - (k - path.size()) + 1; ++i)
        {
            //> ��ʼ����
            path.push_back(i);
            backtracking(n, i + 1, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (k > n)
            return res;
        backtracking(n, 1, k);//> 1 ��ʾ�ڼ������
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};


//> ����ܺ� III
class Solution {
public:
    void backtarvel(int k, int n, int index, int sum)
    {
        //> �����г�����
        if (path.size() == k)
        {
            if (sum == n)
                res.push_back(path);
            return;
        }
        //> �������+��֦
        for (int i = index; i <= 9 - (k - path.size()) + 1; ++i)
        {
            //> ��ʼ����
            sum += i;
            path.push_back(i);
            backtarvel(k, n, i + 1, sum);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum = n;
        //> k , n, ���ݴ�������ǰֵ
        backtarvel(k, n, 1, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    vector<int> path;
};

//> �绰�������ĸ���

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
        //> �����г�����
        if (digits.size() == x)
        {
            res.push_back(s);
            return;
        }
        int digit = digits[x] - '0';
        string sn = smap[digit];
        //> �������
        for (int i = 0; i < sn.size(); ++i)
        {
            //> ��ʼ����
            s.push_back(sn[i]);
            backtricking(digits, x + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0)
            return res;
        //> �����ַ�����ǰ�ַ�����
        backtricking(digits, 0);
        return res;
    }
private:
    vector<string> res;
    string s;
};