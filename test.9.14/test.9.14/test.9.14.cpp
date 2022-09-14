#include <iostream>

using namespace std;

int main()
{
	/*int a = 5, b = 6, w = 1, x = 2, y = 3, z = 4;
	(a = w > x) && (b = y > z);
	cout << a << " " << b;*/
	int m = 65, n = 14;
	while (m != n)
	{
		while (m > n) m = m - n;
		while (n > m) n = n - m;
	}
	int a[2][4];
	printf("%u\n", sizeof(a));
	printf("%u\n", sizeof(*a));
	printf("%u\n", sizeof(**a));
}