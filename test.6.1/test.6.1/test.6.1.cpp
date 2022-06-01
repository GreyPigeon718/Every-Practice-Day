//> 表示数值的字符串
class Solution {
private:
    // 整数的格式可以用[+|-]B表示, 其中B为无符号整数
    bool scanInteger(const string s, int& index) {
        if (s[index] == '+' || s[index] == '-')
            ++index;
        return scanUnsignedInteger(s, index);
    }
    bool scanUnsignedInteger(const string s, int& index) {
        int befor = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > befor;
    }
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
    bool isNumber(string s) {
        if (s.size() == 0)
            return false;
        int index = 0;
        //字符串开始有空格，可以返回true
        while (s[index] == ' ')  //书中代码没有该项测试
            ++index;
        bool numeric = scanInteger(s, index);
        // 如果出现'.'，接下来是数字的小数部分
        if (s[index] == '.') {
            ++index;
            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }
        // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
        if (s[index] == 'e' || s[index] == 'E') {
            ++index;
            // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            numeric = numeric && scanInteger(s, index);
        }
        //字符串结尾有空格，可以返回true
        while (s[index] == ' ')
            ++index;
        return numeric && index == s.size();//最后看是否所有部分都符合，如1a3只会检测第一部分是整数然后是a就不会继续检测了，index!=size，所以返回false
    }
};

//> 火柴拼正方形
class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // 减少搜索量

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};
