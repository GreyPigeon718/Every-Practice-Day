//收件人列表
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        getchar(); //刷新缓冲区
//        while (n--)
//        {
//            string str;
//            getline(cin, str);
//            if (str.find(',') != -1 || str.find(' ') != -1)
//            {
//                str.insert(str.begin(), '"');
//                str.insert(str.end(), '"');
//            }
//            if (n == 0)
//                cout << str << endl;
//            else
//                cout << str << ", ";
//        }
//    }
//    return 0;
//}
//客似云来
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int from, to;
    long long count;
    while (cin >> from >> to)
    {
        count = 0;
        vector<long long> v(80, 0);
        v[0] = 1;
        v[1] = 1;
        for (int i = 2; i < 80; ++i)
        {
            v[i] = v[i - 2] + v[i - 1];
        }
        for (int i = from - 1; i < to; ++i)
        {
            count += v[i];
        }
        cout << count << endl;
    }
    return 0;
}