//客似云来
//#include <iostream>
//
//using namespace std;
//
//long Fib(int x)
//{
//	if (x == 1 || x == 2)
//		return 1;
//	else if (x == 2)
//		return 2;
//	else
//		return Fib(x - 1) + Fib(x - 2);
//}
//int main()
//{
//	int start, end;
//	while (cin >> start >> end)
//	{
//		long sum = Fib(end) - Fib(start);
//		if (end == 2)
//			sum++;
//		cout << sum << endl;
//	}
//	return 0;
//}
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int from, to;
    long long count;
    while(cin >> from >> to)
    {
        count = 0;
        vector<long long> v(80, 0);
        v[0] = 1;
        v[1] = 1;
        for(int i = 2; i < 80; ++i){
            v[i] = v[i - 2] + v[i - 1];
        }
        for(int i = from - 1; i < to; ++i){
            count += v[i];
        }
        cout << count << endl;
    }
    return 0;
}
//剪画布条
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string s, m;
//	while (cin >> s >> m)
//	{
//		int count = 0;
//		for (int i = 0; i < s.size(); ++i)
//		{
//			int j = 0, k = i;
//			while (s[k] == m[j] && k < s.size())
//			{
//				k++;
//				j++;
//			}
//			if (j == m.size())
//			{
//				count++;
//				i = k - 1;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
