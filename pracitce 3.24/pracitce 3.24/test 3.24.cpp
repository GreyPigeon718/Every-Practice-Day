#include<iostream>
using namespace std;
class Date
{
public:
	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int calendar[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = calendar[month];
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				++day;
		}
		return day;
	}


	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if(year < 1 || month < 1 || month > 12||day < 1 || day > GetMonthDay(year , month))
		{
			cout << "cin error! make 1900 - 1 - 1" << endl;
			_year = 1900;
			_month = 1;
			_day = 1;
		}
		else
		{
			_year = year;
			_month = month;
			_day = day;
		}
	}



	// 拷贝构造函数
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._day;
		_month = d._month;
		_day = d._day;
	}


	// 赋值运算符重载
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (*this != d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
	}


	// 析构函数
	~Date()
	{
		//delete []calendar;
	}



	// 日期+=天数
	Date& operator+=(int day)
	{
		if (day < 0)
			return *this -= -day;
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}



	// 日期+天数
	Date operator+(int day)
	{
		Date tmp = (*this);
		return tmp -= day;
	}



	// 日期-天数
	Date operator-(int day)
	{
		Date tmp = (*this);
		return tmp -= day;
	}



	// 日期-=天数
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	
	

	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;
	}



	// 后置++
	Date operator++(int)
	{
		Date d(*this);
		*this += 1;
		return d;
	}



	// 后置--
	Date operator--(int)
	{
		Date d(*this);
		*this -= 1;
		return d;
	}



	// 前置--
	Date& operator--()
	{
		return *this -= 1;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year < d._year)
			return false;
		if (_year == d._year && _month < d._month)
			return false;
		if (_year == d._year && _month == d._month && _day < d._day)
			return false;
		return true;
	}



	// ==运算符重载
	bool operator==(const Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		return false;
	}



	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		if (!((*this) < d))
			return true;
		return false;
	}



	// <运算符重载
	bool operator < (const Date& d)
	{
		if (_year > d._year)
			return false;
		if (_year == d._year && _month > d._month)
			return false;
		if (_year == d._year && _month == d._month && _day > d._day)
			return false;
		return true;
	}



	// <=运算符重载
	bool operator <= (const Date& d)
	{
		if (!((*this) > d))
			return true;
		return false;
	}



	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}



	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		Date max = *this;
		Date min = d;
		int flag = 1;
		if (min > max)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		int day = 0;
		while (min < max)
		{
			++day;
			++min;
		}
		return day * flag;
	}
	void Show() {
		cout << _year << '-' << _month << '-' << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	
};
int main()
{
	Date s(2020, 10, 18);
	s += 10;
	s.Show();
	s += 20;
	s.Show();
	return 0;
}