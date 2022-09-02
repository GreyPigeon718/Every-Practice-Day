#include <iostream>
using namespace std;
class Base
{
public:
	virtual void f(float x) { cout << "Base::f(float)" << x << endl; }
	void g(float x) { cout << "Base::g(float)" << x << endl; }
	void h(float x) { cout << "Base::h(float)" << x << endl; };

};

class Derived :public Base
{
public:
	virtual void f(float x) { cout << "Derived::f(float)" << x << endl; }
	void g(int x) { cout << "Derived::g(int)" << x << endl; }
	void h(float x) { cout << "Derived::h(float)" << x << endl; }
};

int main()
{
	Base temp;
	Derived tester;
	Base* p = &tester;
	temp.h(1.0);
	tester.f(2.0);
	p->f(2.0);
	tester.g(3.0);
	p->g(3.0);
	return 0;

}
////class A
////{
////public:
////	static A* GetInstance()
////	{
////		return (new A(2));
////	}
////	void Destory() { delete this; };
////	void print()
////	{
////		cout << m_data << endl;
////	}
////private:
////	A(int a) :m_data(a) {}
////	~A() {}
////	int m_data;
////};
////
////int main()
////{
////	A* p = A::GetInstance();
////	A* q = new A(3);
////	p->print();
////	q->print();
////	p->Destory();
////	delete q;
////	return 0;
////}
////#include <iostream>
////using namespace std;
////
////void fun1(int& x)
////{
////	x++;
////}
////void fun2(int x)
////{
////	x++;
////}
//////int main()
//////{
//////	int abc = 100, xyz = 13;
//////	fun1(xyz);
//////	abc = xyz;
//////	fun2(abc);
//////	cout << abc;
//////	return 0;
//////}
////
////
//////class A
//////{
//////public:
//////	virtual void func(int val = 1)
//////	{
//////		cout << "A->" << val << endl;
//////	}
//////	virtual void test()
//////	{
//////		func();
//////	}
//////};
//////class B :public A
//////{
//////public:
//////	void func(int val = 0)
//////	{
//////		cout << "B->" << val << endl;
//////	}
//////};
////
//////int main()
//////{
//////	B* p = new B;
//////	p->test();
//////	return 0;
//////}
////
//////int main()
//////{
//////	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//////	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//////	cout << str;
//////}
////struct A
////{
////	char t : 4;
////	char k : 4;
////	unsigned short i : 8;
////	unsigned long m;
////};
////int main()
////{
////	int i = 10, j = 10, k = 3;
////	k*= i + j;
////	int count = 0;
////	int x = 2046;
////	while (x)
////	{
////		count++;
////		x = x & (x - 1);
////	}
////	cout << count << endl;
////	cout << k << endl;
////	cout << sizeof(A);
////}
////
////
////
////int main()
////{
////	long i;
////	float bonus, bon1, bon2, bon4, bon6, bon10;
////	bon1 = 100000 * 0.05; /*����Ϊ10��Ԫʱ�Ľ���*/
////	bon2 = bon1 + 100000 * 0.04; /*����Ϊ20��Ԫʱ�Ľ���*/
////	bon4 = bon2 + 200000 * 0.05; /*����Ϊ40��Ԫʱ�Ľ���*/
////	bon6 = bon4 + 200000 * 0.03; /*����Ϊ60��Ԫʱ�Ľ���*/
////	bon10 = bon6 + 400000 * 0.015; /*����Ϊ100��Ԫʱ�Ľ���*/
////	cin >> i;
////	if (i <= 100000)
////		bonus = i * 0.05; /*������10��Ԫ���ڰ�0.1��ɽ���*/
////	else if (i <= 200000)
////		bonus = bon1 + (i - 100000) * 0.04; /*������10����20��Ԫʱ�Ľ���*/
////	else if (i <= 400000)
////		bonus = bon2 + (i - 200000) * 0.05; /*������20����40��Ԫʱ�Ľ���*/
////	else if (i <= 600000)
////		bonus = bon4 + (i - 400000) * 0.03; /*������40��Ԫ��60��Ԫʱ�Ľ���*/
////	else if (i <= 1000000)
////		bonus = bon6 + (i - 600000) * 0.015; /*������60��Ԫ��100��Ԫʱ�Ľ���*/
////	else bonus = bon10 + (i - 1000000) * 0.01; /*������100��Ԫ����ʱ�Ľ���*/
////	cout << bonus;
////}
//
//#include<stdio.h>
//#include<string.h>//ͷ�ļ���һ��������
//int main()
//{
//	char a[50];
//	int k, i, l, j;
//	while (1)//�������
//	{
//		scanf_s("%s", a);
//		k = 0; l = 0;
//		for (i = 0; i <= strlen(a); i++)
//		{
//			if (a[i] == ' ' || i == strlen(a))//���ʱֱ�ӵ������,�ַ�������и�"\0"
//			{
//				for (j = i - 1; j >= l; j--)
//				{
//					printf("%c", a[j]);
//					k++;
//				}
//				if (a[i] == ' ')
//				{
//					printf(" ");
//				}
//				l = i + 1;//һ����1�����������ظ�
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//
//
//for (int i = 0; i < inString.size(); ++i)
//{
//	if (inString[i] == " ")
//	{
//		reverse(s.begin() + index, s.begin() + i);
//		++i;
//		index = i;
//	}
//}
//reverse(inString.begin() + index, inString.end())