//> ������
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

//> �����ַ���������
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param text_source string�ַ��� ԭʼ����
     * @return string�ַ���
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



//> ����ĵ���
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
        if (banned.empty()) //���û�н��õ��ʣ�ֱ�ӷ���������б���Ԫ��
            return word[0];
        for (auto w : word) //�����ڽ����б��в��ң���һ��û�еĵ��ʾͷ���
            if (ban.find(w) == ban.end())
                return w;
        return "";
    }
};