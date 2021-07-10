//最难的问题
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    while (getline(cin , s))
//    {
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (isupper(s[i]))
//            {
//                if (s[i] < 'F')
//                {
//                    s[i] += 21;
//                }
//                else if (s[i] >= 'F')
//                {
//                    s[i] -= 5;
//                }
//            }
//        }
//        cout << s << endl;
//    }
//    return 0;
//}
//因子个数
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int x;
	while (cin >> x)
	{
		int count = 0;
		for (int i = 2; i <= sqrt(x); ++i)
		{
			if (x % i == 0)
			{
				while (x % i == 0)
					x /= i;
				count++;
			}
		}
		if (x != 1)
			count++;
		cout << count << endl;
	}
	return 0;
}