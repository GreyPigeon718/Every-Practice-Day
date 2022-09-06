// 子矩阵之和

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec;
int gcd(int m, int n)
{
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return gcd(n, m % n);
	}
}
int sumk(int i, int j, int k)//i和j是第一个字符的x,y坐标
{
	int sumk = 0;
	for (int p = i; p < i + k; p++)
	{
		for (int q = j; q < j + k; q++)
		{
			sumk += gcd(p, q);
		}
	}
	return sumk;

}
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	int sum1 = 0;
	for (int i = 1; i <= m - k + 1; i++)
	{
		for (int j = 1; j <= n - k + 1; j++)
		{
			sum1 += sumk(i, j, k);
		}
	}
	cout << sum1 << endl;
	return 0;
}
