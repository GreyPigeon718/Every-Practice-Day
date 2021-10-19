////设计一个程序能计算一个日期加上若干天后是什么日期。
//#include <iostream>
//using namespace std;
//int main()
//{
//    int x;
//    while (cin >> x)
//    {
//        int calendar[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//        for (int i = 0; i < x; ++i)
//        {
//            int year, month, day, num;
//            cin >> year >> month >> day >> num;
//            while (num+day > calendar[month])
//            {
//                if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//                    calendar[2] = 29;
//                else
//                    calendar[2] = 28;
//
//                num -= calendar[month] - day;
//                day = 0;
//                month++;
//                if (month == 13)
//                {
//                    year++;
//                    month = 1;
//                }
//            }
//            
//            if (num + day < calendar[month])
//                num += day;
//            printf("%4d-%02d-%02d\n", year, month, num);
//        }
//    }
//}
//
////计算一年的第几天
//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//    int monthDays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
//    int year, month, day;
//    while (cin >> year >> month >> day)
//    {
//        int outday = 0;
//        outday = monthDays[month - 1] + day;
//        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
//        {
//            if (month > 1)
//                outday++;
//        }
//        cout << outday << endl;
//    }
//}
#include <iostream> 
#define pi 3.1416
class planet
{
protected:
	double distance;               // miles from the sun 
	int revolve;                   // in days 
public:
	planet(double d, int r)        //构造函数
	{
		distance = d;
		revolve = r;
	}
};
class earth : public planet        //派生类earth 
{
	double circumference;          // circumference of orbit 
public:
	earth(double a, int b) :
		planet(a,b)
	{
		circumference = 2 * pi * a * 365;
	}

	void show()
	{
		printf("%lf", circumference);
	}
};
int main()
{
	earth ob(93000000, 365);
	ob.show();
	return 0;
}