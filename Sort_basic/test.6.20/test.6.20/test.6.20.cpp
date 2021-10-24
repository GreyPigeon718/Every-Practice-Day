//Êý¸ù
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	unsigned long long  x;
//	while (cin >> x)
//	{
//		int y = (x - 1) % 9 + 1;
//		cout << y << endl;
//	}
//	return 0;
//}
#include<iostream>
#include<string>
using namespace std;
int numsum(int num)
{
    int sum = 0;
    if (num == 0)
        return 0;
    if (num)
    {
        sum += num % 10 + num / 10;
    }
    if (sum > 9)
        return numsum(sum);
    else
        return sum;

}
int main()
{
    string x;
    while (cin >> x)
    {
        int y = 0;
        for (int i = 0; i < x.size(); ++i)
        {
            y += x[i] - '0';
        }
        cout << numsum(y) << endl;
    }
    return 0;
}
