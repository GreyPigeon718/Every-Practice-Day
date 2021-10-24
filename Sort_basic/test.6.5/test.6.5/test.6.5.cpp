//#include <iostream>
//
//using namespace std;
//
////class A {
////	;
////};
////A :: ~A()
////{
////	delete this;
////	this = NULL;
////}
//
//void func(const int& v1, const int& v2)
//{
//    std::cout << v1 << ' ';
//    std::cout << v2 << ' ';
//}
//
//struct st_task
//{
//    uint16_t id;
//    uint32_t value;
//    uint64_t timestamp;
//};
//
//void fool()
//{
//    st_task task = {};
//    uint64_t a = 0x00010001;
//    memcpy(&task, &a, sizeof(uint64_t));
//    printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
//}
//int main()
//{
//    int i = 0;
//    //func(++i, i++);
//    fool();
//    return 0;
//}
//#include "stdio.h"
//class Base
//{
//public:
//    int Bar(char x)
//    {
//        return (int)(x);
//    }
//    virtual int Bar(int x)
//    {
//        return (2 * x);
//    }
//};
//class Derived : public Base
//{
//public:
//    int Bar(char x)
//    {
//        return (int)(-x);
//    }
//    int Bar(int x)
//    {
//        return (x / 2);
//    }
//};
//int main(void)
//{
//    Derived Obj;
//    Base* pObj = &Obj;
//    printf("%d,", pObj->Bar((char)(100)));
//    printf("%d,", pObj->Bar(100));
//}

//二进制插入
//#include <iostream>
//
//using namespace std;
//int main()
//{
//    int n, m, j, i;
//    cin >> n >> m >> j >> i;
//    m = m << j;
//    n |= m;
//    cout << n << endl;
//    return 0;
//}
//查找组成一个偶数最接近的两个素数
#include <iostream>

using namespace std;
bool prime(int x)
{
	for (int i = 2; i < x / 2; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int num;
	while (cin >> num)
	{

		int x = num / 2;
		while (!(prime(x) && prime(num - x)))
		{
			x--;
		}
		cout << x << endl;
		cout << num - x << endl;
	}
	return 0;
}