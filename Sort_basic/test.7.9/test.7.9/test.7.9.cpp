//#include <iostream>
//using namespace std;
//
//
//int main(void)
//{
//    http://www.taobao.com
//    cout << "welcome to taobao" << endl;
//    return 0;
//}
//ÓÐ¼Ù±Ò
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int  a;
    while (cin >> a)
    {
        int count = 0;
        if (a == 0)
            break;
        while (a > 0)
        {
            count++;
            a = a / 3 + (a % 3 > 0);
        }
        cout << count << endl;
    }
    return 0;
}