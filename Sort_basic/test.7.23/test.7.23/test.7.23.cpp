#include <iostream>
#include <map>
using namespace std;
template<class T> void f(T& i) { cout << 1; }
template<> void f(const int& i) { cout << 2; }
struct number {
	
	long b;
};
int main()
{
	cout << sizeof(0xAABBBCCDD);
	
	//const string& rs = 0;
	//string rs;
	//string* ps = &rs;

	
}