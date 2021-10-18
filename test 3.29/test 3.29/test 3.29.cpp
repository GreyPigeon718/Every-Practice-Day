//#include <iostream>
//using namespace std;
//int main()
//{
//	//string s = "hello";
//	//s.append("123");
//	//cout << s.at(4);
//}
//给出年分m和一年中的第n天，算出第n天是几月几号。
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int year, day;
//    while (cin >> year >> day)
//    {
//        int calendar[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//            calendar[2] = 29;
//        int month = 1;
//        while (day > calendar[month])
//        {
//            day -= calendar[month];
//            month++;
//        }
//        printf("%04d-%02d-%02d", year, month, day);
//    }
//}

//女朋友作业简单计算器
//#include<iostream>
//using namespace std;
//class counter                  //counter类的定义
//{
//public:                        //外部接口
//	counter(int number)       //构造函数
//	{
//		value = number;
//	}
//	counter(const counter& d)
//	{
//		value = d.value;
//	}
//	counter& operator+=(int number)
//	{
//		value += number;
//		return *this;
//	}
//	counter& operator++()
//	{
//		*this += 1;
//		return *this;
//	}
//	counter operator++(int)
//	{
//		counter d(*this);
//		*this += 1;
//		return d;
//	}
//	counter& operator-=(int number)
//	{
//		value -= number;
//		return *this;
//	}
//	counter& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//	counter operator--(int)
//	{
//		counter d(*this);
//		*this -= 1;
//		return d;
//	}
//	void Print()
//	{
//		cout << value << endl;
//	}
//private:                       
//	int value;
//};
//int main()
//{
//	int a;
//	scanf_s("%d", &a);
//	counter b(a);
//	b++;
//	b.Print();
//	b--;
//	b.Print();
//	return 0;
//}
#include<iostream>
using namespace std;
int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
int CountDay(int y, int m, int d)
{
    // 计算0-y年的天数
    int yearDay = y * 365 + y / 4 - y / 100 + y / 400;
    // 计算到0-m月的天数
    int monthDay = mon[m - 1];

    if (m > 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        monthDay += 1;

    return yearDay + monthDay + d;
}

int main()
{
    int year1, month1, day1;
    scanf_s("%4d%2d%2d", &year1, &month1, &day1);
    int n1 = CountDay(year1, month1, day1);

    int year2, month2, day2;
    scanf_s("%4d%2d%2d", &year2, &month2, &day2);
    int n2 = CountDay(year2, month2, day2);

    cout << abs(n1 - n2) + 1 << endl;
}
