//> �ƽ�ͫ
//> ���ӣ�Сׯ��һ�λ�Ե�ɺϵĻ��ᣬ�۾���ȡ�˻ƽ�ͫ���ƽ�ͫ�Ĺ����ǿ��Կ���m����Ʒ10���Ժ�ļ۸񡣵�����Щ��Ʒ�����޹����ʣ����ֻ�ܹ���һ��������������Сׯ���ʽ�x����Ͷ����Щ��Ʒ����β�������ʵ��10����ʲ���ֵ���
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

//> �λ�Ĳ���
//> ���ӣ���˾�����϶�ȥ���������簲ȫ��ᡱѧϰ�Ļ��ᣬ���췽�ڹ��һ�������һ���а����˼�ʮ���ֻ᳡��ͬʱ���и���������飬�᳡�������С��϶ŵĲ����ǣ��μӾ����ܶ�Ļ��飬�����϶��õ��˵������л�����ճ̱�������ÿ������Ŀ�ʼ����ʱ���[starttime, endtime]������ʱ�䶼Ϊ�����������϶���������ܲμӼ������飿
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param times int����vector<vector<>>
     * @return int����
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

//> ��ת����˳��
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

//> ���һ�����ʵĳ���
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


//> ��ת�ַ����еĵ��� III
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

//> �ضϾ���
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