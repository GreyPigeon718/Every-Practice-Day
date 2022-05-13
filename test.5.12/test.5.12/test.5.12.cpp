//> n阶奇数幻方
//> 规律：
//> 1.1在n/2的位置
//> 2.依次向45°顺序填数字
//> 3.越过边界，还是行+1，列-1
//> 4.如果顺序位置被占，则在正下方填。
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void MagicCube(int n)
{
	int** Matr = new int* [n];
	for (int i = 0; i < n; i++)
		Matr[i] = new int[n];
	int j = n / 2; //j=n/2指的以首行中间数作为起点，即1所在的位置
	int num = 1;
	int i = 0;
	//> i为行，j为列
	while (num != n * n + 1)
	{
		//往右上角延升，若超出则用%转移到左下角
		Matr[(i % n + n) % n][(j % n + n) % n] = num;
		//斜行的长度是n，超出则转至下一斜行
		if (num % n == 0)
			i++;
		else
		{
			i--;  //记录行
			j++;  //记录列
		}
		num++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw((int)log10(n * n) + 4) << Matr[i][j]; //格式控制
		cout << endl << endl;   //格式控制
	}
	for (i = 0; i < n; i++)
		delete[]Matr[i];
}

int main()
{
	int n;
	cin >> n;
	MagicCube(n);
	cout << -1 % 5 << endl;
	return 1;
}