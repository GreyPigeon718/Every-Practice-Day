//> 黄金瞳
//> 链接：小庄在一次机缘巧合的机会，眼睛获取了黄金瞳，黄金瞳的功能是可以看到m种物品10天以后的价格。但是这些物品属于限购物资，最多只能购买一定的数量。现在小庄有资金x可以投资这些物品，如何操作才能实现10天后资产价值最大。
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int bagSize;
    cin >> bagSize;
    int num;
    cin >> num;
    vector<int> nums(num);
    for (int i = 0; i < num; ++i) {
        cin >> nums[i];
    }
    vector<int> weights(num);
    for (int i = 0; i < num; ++i) {
        cin >> weights[i];
    }
    vector<int> values(num);
    for (int i = 0; i < num; ++i) {
        cin >> values[i];
    }
    for (int i = 0; i < num; ++i) {
        int count = nums[i];
        while (count > 1) {
            weights.emplace_back(weights[i]);
            values.emplace_back(values[i]);
            --count;
        }
    }
    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < weights.size(); ++i) {
        for (int j = bagSize; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    //    for (auto& w : weights) cout << w << ' ';
    //    cout << endl;
    //    for (auto& v : values) cout << v << ' ';
    //    cout << endl;
    int i = bagSize;
    while (i > 0 && dp[i] == dp[i - 1]) {
        --i;
    }
    int res = dp[i] + bagSize - i;
    cout << res << endl;
    return 0;
}

//> 参会的策略
//> 链接：公司给了老杜去“北京网络安全大会”学习的机会，主办方在国家会议中心一天中安排了几十个分会场在同时举行各种主题会议，会场人声鼎沸。老杜的策略是：参加尽可能多的会议，于是老杜拿到了当天所有会议的日程表，表上是每个会议的开始结束时间段[starttime, endtime]，假设时间都为整数，请问老杜这天最多能参加几个会议？
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param times int整型vector<vector<>>
     * @return int整型
     */
    int AttendMeetings(vector<vector<int> >& times) {
        // write code here
        int count = 1;
        sort(times.begin(), times.end(), [](vector<int> a, vector<int> b)
            {return a[1] < b[1]; });
        int end = times[0][1];
        for (int i = 1; i < times.size(); ++i)
        {
            if (times[i][0] >= end)
            {
                end = times[i][1];
                count++;
            }
        }
        return count;
    }
};

//> 翻转单词顺序
class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string tmp = "";
        vector<string> res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (!tmp.empty())
                {
                    res.emplace_back(tmp);
                    tmp.clear();
                }
            }
            else
                tmp += s[i];
        }
        s.clear();
        reverse(res.begin(), res.end());
        for (string& str : res)
            s += str + " ";
        s.pop_back();
        return s;
    }
};

//> 最后一个单词的长度
class Solution {
public:
    int lengthOfLastWord(string s) {
        s += " ";
        string tmp = "";
        vector<string> res;
        for (auto str : s)
        {
            if (str == ' ')
            {
                if (!tmp.empty())
                {
                    res.emplace_back(tmp);
                    tmp.clear();
                }
            }
            else
                tmp += str;
        }
        if (res.empty())
            return 0;
        return res.back().size();
    }
};


//> 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
        s += " ";
        string tmp = "";
        vector<string> res;
        for (auto str : s)
        {
            if (str == ' ')
            {
                if (!tmp.empty())
                {
                    res.emplace_back(tmp);
                    tmp.clear();
                }
            }
            else
                tmp += str;
        }
        s.clear();
        for (auto& str : res)
        {
            reverse(str.begin(), str.end());
            s += str + " ";
        }
        s.pop_back();
        return s;
    }
};

//> 截断句子
class Solution {
public:
    string truncateSentence(string s, int k) {
        s += " ";
        string tmp = "";
        vector<string> res;
        for (auto str : s)
        {
            if (str == ' ')
            {
                if (!tmp.empty())
                {
                    res.emplace_back(tmp);
                    tmp.clear();
                }
            }
            else
                tmp += str;
        }
        s.clear();
        for (int i = 0; i < k; ++i)
        {
            s += res[i] + " ";
        }
        s.pop_back();
        return s;
    }
};