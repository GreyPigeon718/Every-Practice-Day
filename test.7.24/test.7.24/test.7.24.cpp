//> 汉宁窗
#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.1415827
int main()
{
	int window;
	cin >> window;
	int n = 0;
	int windows = window;
	while (window--)
	{
		int x;
		cin >> x;
		double res = x * 0.5 * (1 - cos(2 * PI * n / windows));
		++n;
		if (res > 0)
		{
			int ans = int(res + 0.5);
			cout << ans << " ";
		}
		else
		{
			int ans = int(res - 0.5);
			cout << ans << " ";
		}
	}
	return 0;
}

//> 重排字符串和数字
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param text_source string字符串 原始输入
     * @return string字符串
     */
    string char_and_num_return(string text_source) {
        // write code here
        vector<string> strs;
        vector<long long> nums;
        string str = "";
        int flag = 0;
        text_source += ' ';
        for (auto& ch : text_source)
        {
            if (ch == ' ')
            {
                if (flag == 1)
                {
                    nums.emplace_back(stoll(str));
                }
                else if (flag == 2)
                {
                    strs.emplace_back(str);
                }
                flag = 0;
                str.clear();
            }
            else if (ch >= '0' && ch <= '9')
            {
                flag = 1;
                str += ch;
            }
            else
            {
                flag = 2;
                str += ch;
            }
        }
        string ans = "";
        sort(nums.begin(), nums.end());
        if (!strs.empty())
        {
            for (int i = 0; i < strs.size(); ++i)
            {
                ans += strs[i];
                if (i != strs.size() - 1)
                    ans += ' ';
            }
        }
        if (!nums.empty())
        {
            if (!ans.empty())
                ans += ' ';
            for (int i = 0; i < nums.size(); ++i)
            {
                ans += to_string(nums[i]);
                if (i != nums.size() - 1)
                    ans += ' ';
            }
        }
        return ans;
    }
};



//> 最常见的单词
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> ump;
        string tmp = "";
        paragraph += ' ';
        set<string> ban(banned.begin(), banned.end());

        for (char ch : paragraph)
        {
            if (!isalpha(ch))
            {
                if (!tmp.empty())
                {
                    ump[tmp]++;
                    tmp.clear();
                }
            }
            else
            {
                tmp += tolower(ch);
            }
        }
        vector<string> word;
        for (auto p : ump)
            word.emplace_back(p.first);
        sort(word.begin(), word.end(), [&](string& a, string& b) {return ump[a] > ump[b]; });
        if (banned.empty()) //如果没有禁用单词，直接返回排序后列表首元素
            return word[0];
        for (auto w : word) //否则在禁用列表中查找，第一个没有的单词就返回
            if (ban.find(w) == ban.end())
                return w;
        return "";
    }
};