#include <iostream>

using namespace std;

typedef struct Z
{
	int f;
	int g;
	int* p;
};
typedef struct A
{
	int b;
	int* c;
	Z z;
}A;

int main()
{
	A x;
	A* y = &x;
	A** a = &y;
	(*a)[0].z.p = (int*)10;
	return 0;
}