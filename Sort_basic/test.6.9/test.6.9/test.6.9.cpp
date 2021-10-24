#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//
//using namespace std;
//class A
//{
//public:
//    A()
//    {
//        printf("A ");
//    }
//
//    ~A()
//    {
//        printf("deA ");
//    }
//};
//
//class B
//{
//public:
//    B()
//    {
//        printf("B ");
//    }
//    ~B()
//    {
//        printf("deB ");
//    }
//};
//
//class C : public A, public B
//{
//public:
//    C()
//    {
//        printf("C ");
//    }
//    ~C()
//    {
//        printf("deC ");
//    }
//};
//static int a = 1;
//void fun1(void) { a = 2; }
//void fun2(void) { int a = 3; }
//void fun3(void) { static int a = 4; }
//int main(int argc, char** args) {
//    printf("%d",a);
//    fun1();
//    printf("%d", a);
//
//    fun2();
//    printf("%d", a);
//
//    fun3();
//    printf("%d", a);
//
//}
//int main()
//{
//    A* a = new C();
//    delete a;
//    return 0;
//}
//int FindSubString(char* pch)
//{
//    int   count = 0;
//    char* p1 = pch;
//    while (*p1 != '\0')
//    {
//        if (*p1 == p1[1] - 1)
//        {
//            p1++;
//            count++;
//        }
//        else {
//            break;
//        }
//    }
//    int count2 = count;
//    while (*p1 != '\0')
//    {
//        if (*p1 == p1[1] + 1)
//        {
//            p1++;
//            count2--;
//        }
//        else {
//            break;
//        }
//    }
//    if (count2 == 0)
//        return(count);
//    return(0);
//}
//void ModifyString(char* pText)
//{
//    char* p1 = pText;
//    char* p2 = p1;
//    while (*p1 != '\0')
//    {
//        int count = FindSubString(p1);
//        if (count > 0)
//        {
//            *p2++ = *p1;
//            sprintf(p2, "%i", count);
//            while (*p2 != '\0')
//            {
//                p2++;
//            }
//            p1 += count + count + 1;
//        }
//        else {
//            *p2++ = *p1++;
//        }
//    }
//}
//void main(void)
//{
//    char text[32] = "XYBCDCBABABA";
//    ModifyString(text);
//    printf(text);
//}
//查找输入整数二进制1的个数
//#include <iostream>
//
//using namespace std;
//
//
//int findNumberOf1(int num)
//{
//	int count = 1;
//	while (num & (num - 1))
//	{
//		num &= (num - 1);
//		count++;
//	}
//	return count;
//}
//
//int main()
//{
//	int x;
//	while (cin >> x)
//	{
//		int n = findNumberOf1(x);
//		cout << n << endl;
//	}
//	return 0;
//}
//手套
//int findMinimum(int n, vector<int> left, vector<int> right) {
//    // write code here
//    int sum = 0;
//    int leftSum = 0, rightSum = 0;
//    int leftMin = INT_MAX, rightMin = INT_MAX;
//    for (int i = 0; i < n; i++)
//    {
//        if (left[i] * right[i] == 0)
//            sum += (left[i] + right[i]);
// 
//        else
//        {
//            leftSum += left[i];
//            rightSum += right[i];
//            leftMin = min(leftMin, left[i]);
//            rightMin = min(rightMin, right[i]);
//        }
//    }
//    return sum + min(leftSum - leftMin + 1, rightSum - rightMin + 1) + 1;
//}
//#include<iostream>
//using namespace std;
//
//class Base
//{
//public:
//    virtual int foo(int x)
//    {
//        return x * 10;
//    }
//
//    int foo(char x[14])
//    {
//        return sizeof(x) + 10;
//    }
//};
//
//class Derived : public Base
//{
//    int foo(int x)
//    {
//        return x * 20;
//    }
//
//    virtual int foo(char x[10])
//    {
//        return sizeof(x) + 20;
//    }
//};
//
//int main()
//{
//    Derived stDerived;
//    Base* pstBase = &stDerived;
//
//    char x[10];
//    printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
//
//    return 0;
//}
//完全数
#include <iostream>
 
using namespace std;

bool perfectnum(int x)
{
	int sum = 0;
	for (int i = 1; i < x; ++i)
	{
		if (x % i == 0)
		{
			sum += i;
		}
	}
	if (sum == x)
		return true;
	return false;
}
int main()
{
	int x;
	cin >> x;
	int count = 0;
	for (int i = 1; i < x; ++i)
	{
		if (perfectnum(i))
			count++;
	}
	cout << count << endl;
	return 0;
}