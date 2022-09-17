#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void test(int& t)
{
	cout << "int&" << endl;
}
void test(const int& t)
{
	cout << "const int&" << endl;
}

void test(int&& t)
{
	cout << "int&&" << endl;
}

void test(const int&& t)
{
	cout << "const int&"<< endl;
}
void forward_test(int&& a)
{
	test(a);
}
int main()
{
	int t = 0;
	int &p = t;
	forward_test(forward<int&&>(t));
	cout << typeid(p).name();
	return 0;
}