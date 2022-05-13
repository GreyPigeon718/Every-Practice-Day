//> n�������÷�
//> ���ɣ�
//> 1.1��n/2��λ��
//> 2.������45��˳��������
//> 3.Խ���߽磬������+1����-1
//> 4.���˳��λ�ñ�ռ���������·��
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void MagicCube(int n)
{
	int** Matr = new int* [n];
	for (int i = 0; i < n; i++)
		Matr[i] = new int[n];
	int j = n / 2; //j=n/2ָ���������м�����Ϊ��㣬��1���ڵ�λ��
	int num = 1;
	int i = 0;
	//> iΪ�У�jΪ��
	while (num != n * n + 1)
	{
		//�����Ͻ�����������������%ת�Ƶ����½�
		Matr[(i % n + n) % n][(j % n + n) % n] = num;
		//б�еĳ�����n��������ת����һб��
		if (num % n == 0)
			i++;
		else
		{
			i--;  //��¼��
			j++;  //��¼��
		}
		num++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << setw((int)log10(n * n) + 4) << Matr[i][j]; //��ʽ����
		cout << endl << endl;   //��ʽ����
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