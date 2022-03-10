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
// ţ�ٵ�����
//> ���������ߵ�����Լ����Ҳ����Ϊʲôţ�ٵ�����������
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