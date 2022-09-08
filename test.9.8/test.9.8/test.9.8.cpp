#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

int minOptionNum(string s)
{
	unordered_map<int, int> ump;
	int count = 0; // 字符类型个数
	int res = 0;
	ump[s[0]]++;
	set<char> st;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] != s[i - 1])
			count++;
		ump[s[i]]++;
		st.insert(s[i]);
	}
	//因为是通过排序比较相邻是否不同，所有最后count要加1
	count += 1;
	cout << count << endl;
	int avcount = 26 - count;// 未使用的字符类型
	for (char c : st)
	{
		while (ump[c] > 1)
		{
			if (avcount > 0)
			{
				ump[c] -= 2;
				avcount--;
			}
			else
				ump[c]--;
			res++;
		}
		if (ump[c] == 0)
			avcount++;
	}
	return res;
}
int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << endl;
	cout << minOptionNum(s);
}