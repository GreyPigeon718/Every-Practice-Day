//#include <iostream>
//using namespace std;
//
//
//    /*char acX[] = "abc";
//    char acY[] = { 'a','b','c' };
//    char* szX = "abc";
//    char* szY = "abc";*/
//#include<iostream>
//using namespace std;
//class Sample {
//public:
//		Sample(int x) {
//			p = new int(x);
//		}
//		~Sample() {
//			if (p) delete p;
//		}
//		int show() {
//			return *p;
//		}
//	private:
//		int* p;
//	};
//
//	int main() 
//	{
//		Sample S(5);
//		cout << S.show() << endl;
//		return 0;
//}

//ÅÅÁÐ×ÓÐòÁÐ
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n, m = 0, count = 0;
//    cin >> n;
//    vector<long> v(n+1);
//    for (long i = 0; i < n; i++)
//    {
//        cin >> v[i];
//    }
//    while (m < n)
//    {
//        if (v[m] < v[m + 1])
//        {
//            while (v[m] <= v[m + 1] && m < n - 1)
//                m++;
//            count++;
//            m++;
//        }
//        else if (v[m] > v[m + 1])
//        {
//            while (v[m] > v[m + 1] && m < n - 1)
//                m++;
//            count++;
//            m++;
//        }
//        else
//            m++;
//    }
//    cout << count << endl;
//    return 0;
//}
//µ¹ÖÃ×Ö·û´®
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    int place = 0;
    int placed = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
    
        {
            place = i;
            reverse(s.begin()+placed, s.begin() + place);
            placed = place + 1;
            i++;
        }
    }
    reverse(s.begin() + place+1 , s.end());
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}