#include <iostream>
using namespace std;

//int main()
//{
//	int i;
//	while (cin >> i)
//	{
//		i = 0x5f3759df - (i >> 1);
//		cout << i << endl;
//	}
//}
// 牛顿迭代法
//> 切线是曲线的线性约束，也就是为什么牛顿迭代法会收敛
double mysqrt(int x)
{
	double y = x >> 1;
	while (true)
	{
		if (abs(y * y - x) < 0.00001)
			break;
		y = y - (y * y - x) / (2 * y);
	}
	return y;
}

int main()
{
	int x; 
	while (cin >> x)
	{
		double res = mysqrt(x);
		cout << res << endl;
	}
	return 0;
}