//年终会奖金
//#include<iostream>
//#include<cmath>
//using namespace std;
////1.概率：n个人取到的不是自己名字的序列个数/n个人可能抽取的所有可能性
//long long NotSelf(int n)//n个人取不到自己名字的可能性
//{
//    if (n == 1)
//        return 0;
//    if (n == 2)
//        return 1;
//    return (n - 1) * (NotSelf(n - 1)/*第一种情况：其他人取到了特定人的名字*/
//        + NotSelf(n - 2)/*第二种情况：特定人和被选的人相互拿到对方的名字*/);
//}
//long long Count(int n)
//{
//    double m = 1;
//    for (int i = 2; i <= n; ++i)//n的阶乘
//        m *= i;
//    return m;
//}
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        double ret = (double)NotSelf(n) / Count(n);         //计算概率
//        printf("%2.2f%%\n", ret * 100);
//    }
//    return 0;
//}
//抄送列表
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> str;
		size_t pos = 0;
		while (pos < s.size())
		{
			if (s[pos] == '\"')
			{
				size_t end = s.find('\"', pos + 1);
				str.push_back(s.substr(pos + 1, end - pos - 1));//把双引号去掉
				pos = end + 2;//逗号和双引号
			}
			else
			{
				size_t end = s.find(',', pos + 1);
				if (end == -1)
				{
					str.push_back(s.substr(pos, s.size() - pos));
					break;
				}
				str.push_back(s.substr(pos, end - pos));
				pos = end + 1;
			}
		}
		getline(cin, s);
		if (str.end() == find(str.begin(), str.end(), s))
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}