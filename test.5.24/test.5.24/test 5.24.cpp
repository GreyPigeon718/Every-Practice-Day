//#include <iostream>
//int main(void)
//
//{
//
//	printf("%s , %5.3s\n", "computer", "computer");
//
//	return 0;
//
//}
//牛客网组队竞赛
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n,sum_max = 0;
//    cin >> n;
//    vector<int> v(n * 3);
//    for (int i = 0; i < n * 3; i++)
//    {
//        cin >> v[i];
//    }
//    sort(v.begin(), v.end());
//    for (int j = 0; j < n ; j++)
//    {
//        sum_max += v[n * 3 - 1 - j*2 -1];
//    }
//    cout << sum_max << endl;
//    return 0;
//}
//删除公共字符串


#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s_main, dele_s;
	getline(cin,s_main);
	getline(cin, dele_s);
	for (int i = 0; i < s_main.size(); i++)
	{
		for (int j = 0; j < dele_s.size(); j++)
		{
			if (s_main[i] == dele_s[j])
			{
				s_main.erase(s_main.begin() + i);
			}
		}
	}
	cout << s_main << endl;

	return 0;
}