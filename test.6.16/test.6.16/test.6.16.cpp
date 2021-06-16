//MP3光标位置
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main(int argc, char* argv[])
//{
//    int list;
//    string s;
//    while (cin >> list >> s)
//    {
//        int index = 1;
//        if (list <= 4)
//        {
//            for (int i = 0; i < s.size(); ++i)
//            {
//                if (index == 1 && s[i] == 'U')
//                    index = list;
//                else if (s[i] == 'U')
//                    index--;
//                else if (index = list && s[i] == 'D')
//                    index = 1;
//                else if (s[i] == 'D')
//                    index++;
//            }
//            for (int i = 0; i < s.size() - 1; ++i)
//            {
//                cout << i + 1 << ' ';
//            }
//            cout << list << endl;
//            cout << index << endl;
//        }
//        else {
//            vector<int> v(4);
//            for (int i = 0; i < 4; ++i)
//            {
//                v[i] = i + 1;
//            }
//            for (int j = 0; j < s.size(); ++j)
//            {
//                if (index == 1 && s[j] == 'U')
//                {
//                    index = list;
//                    for (int k = 0; k < 4; ++k)
//                    {
//                        v[3 - k] = list - k;
//                    }
//                }
//                else if (s[j] == 'U')
//                {
//                    if (index == v[0])
//                    {
//                        for (int i = 0; i < 4; i++)
//                        {
//                            v[i] -= 1;
//                        }
//                    }
//                    index--;
//                }
//                else if (index == list && s[j] == 'D')
//                {
//                    index = 1;
//                    for (int k = 0; k < 4; ++k)
//                    {
//                        v[k] = k + 1;
//                    }
//                }
//                else if (s[j] == 'D')
//                {
//                    if (index = v[3])
//                    {
//                        for (int i = 0; i < 4; ++i)
//                        {
//                            v[i] += 1;
//                        }
//                    }
//                    index++;
//                }
//            }
//            for (int i = 0; i < 3; ++i)
//            {
//                cout << v[i] << ' ';
//            }
//            cout << v[3] << endl;
//            cout << index << endl;
//        }
//    }
//}
//小易的升级之路
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x, y;
	while (~scanf("%d %d", &x, &y))
	{
		vector<int> v(x);
		for (int i = 0; i < x; ++i)
		{
			cin >> v[i];
			if (y >= v[i])
				y += v[i];
			else
			{
				int max = v[i], min = y, com = 0;
				while (max % min != 0)
				{
					com = max % min;
					max = min;
					min = com;
				}
				y += min;
			}
		}
		cout << y << endl;
	}
	return 0;
}