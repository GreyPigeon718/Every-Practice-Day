//#include <iostream>
//#include <string.h>
//using namespace std;
//
//int Function(unsigned int n) {
//
//	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
//	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
//	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
//	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
//	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
//
//	return n;
//}
//
//int main(int argc, int* argv[])
//{
//	int x = Function(197);
//	char str[] = "glad to test something";
//	char* p = str;
//	p++;
//	int* p1 = reinterpret_cast<int*>(p);
//	p1++;
//	p = reinterpret_cast<char*>(p1);
//	printf("result is %s\n", p);
//	char ccString1[] = "Is Page Fault??";
//	char ccString2[] = "No Page Fault??";
//	strcpy_s(ccString1, "No");
//	if (strcmp(ccString1, ccString2) == 0)
//		cout << ccString2;
//	else
//		cout << ccString1;
//
//}

//计算日期到天数的转换
#include <iostream>

using namespace std;

static int calendar[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main(int argc, char* argv[])
{
	int year, month, day;
	int sum = 0;
	while (cin >> year >> month >> day)
	{
		calendar[2] = 28;
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			calendar[2] ++;
		}
		for (int i = 0; i < month; ++i)
		{
			sum += calendar[i];
		}
		sum += day;
		cout << sum << endl;
	}
	return 0;
}