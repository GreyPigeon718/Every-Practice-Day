//×Ö·û´®·´×ª
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	string s;
//	cin >> s;
//	reverse(s.begin(), s.end());
//	cout << s << endl;
//	return 0;
//}
//¹«¹²×Ö·û´®¼ÆËã
//#include <iostream>
//#include <string>
//
//using namespace std;
//int getCommonStrLength(string pFirstStr, string pSecondStr)
//{
//    int max = 0;
//    for (int i = 0; i < pFirstStr.size(); i++)
//    {
//        int begin = i;
//        for (int j = 0; j < pSecondStr.size(); j++)
//        {
//            int begin1 = j;
//            int count = 0;
//            while (j < pSecondStr.size() && ((pFirstStr[i] == pSecondStr[j] || (pFirstStr[i] + 32 - 'a') % 32 == (pSecondStr[j] + 32 - 'a') % 32)))
//            {
//                count++;
//                j++;
//                i++;
//            }
//            if (count > max)
//            {
//                max = count;
//            }
//            j = begin1;
//            i = begin;
//        }
//        i = begin;
//    }
//    return max;
//}
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	int length = getCommonStrLength(a, b);
//    cout << length << endl;
//    return 0;
//}
//Ï´ÅÆ
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		vector<int> table(2*n);

		for (int i = 0; i < 2*n; i++)
			cin >> table[i];

		vector<int> v(table.begin(), table.end());

		while (k--)
		{
			int index = 0;
			int left = (v.size() / 2) - 1;
			int right = v.size() - 1;

			while (left >= 0 && right >= (v.size() / 2))
			{

				table[index++] = v[right--];
				table[index++] = v[left--];
			}
			for (int i = 0; i < table.size(); i++)
				v[i] = table[table.size() - 1 - i];
		}
		for (int i = 0; i < v.size() - 1; i++)
			cout << v[i] << " ";
		cout << v[v.size() - 1] << endl;
	}
	return 0;
}