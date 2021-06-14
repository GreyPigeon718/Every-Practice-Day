//#include <iostream>
//
//using namespace std;
//
//bool fun(int n) {
//    int sum = 0;
//    for (int i = 1; n > sum; i = i + 2)
//        sum = sum + i;
//    return (n == sum);
//}
//
//int main(int argc,char * argv[])
//{
//    cout <<fun(484) << endl;
//}
//汽水瓶
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//	int x;
//	while (cin>> x)
//	{
//		if (x == 0)
//			return 0;
//		int blank = x;
//		int newblank = 0;
//		int sum = 0;
//		while (blank > 1)
//		{
//			sum += blank / 3;
//			blank = blank % 3 + blank / 3;
//			if (blank == 2)
//			{
//				sum++;
//				break;
//			}
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}
//查找两个字符串a，b的最长公共字串
#include <iostream>
#include <string>
using namespace std;

string Find(string a, string b)
{
    string s1 = "";
    for (int i = 0; i < a.size(); i++)
    {
        string s2 = "";
        for (int j = 0; j < b.size(); j++)
        {
            int m = i;
            while (a[m] == b[j])
            {
                s2 += a[m];
                m++;
                j++;
            }
            if (s2.size() > s1.size())
                s1 = s2;
            s2 = "";
        }
    }
    return s1;
}
int main()
{
    string a;
    string b;
    while (cin >> a >> b)
    {
        if (a.size() > b.size())
            swap(a, b);
        string s = Find(a, b);
        cout << s << endl;
    }
    return 0;
}