#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	int a[] = { 3,6,4,8,5,6 };
	do {
		a[i] -= 3;
	} while (a[i++] < 4);
	for (i = 0; i < 6; i++)
	{
		printf("%d", a[i]);
	}
}