//(4)ģ�½̲��С���1.11���ĳ��򣬱�дһ��C++����ʹ��new���ٶ�̬�洢��
//Ԫ����������֣�����ʾ��������֣������Ϻ�ʹ��delete�ͷŶ�̬�洢��Ԫ��
//(5)�Ķ�����ĳ��򣬽����е�ָ�뺯�������޸�Ϊ������Ϊ������
//#include<iostream.h>
//voidf(inta[], intn, int* max, int* min)
//{
//	*max = *min = a[0];
//	for (inti = 1; i < n; i++)
//	{
//		if (*max < a[i])*max = a[i];
//		if (*min > a[i])*min = a[i];
//	}
//}
//voidmain()
//{
//	inta[10] = { 2,5,3,9,0,8,1,7,6,4 };
//	intmax, min;
//	f(a, 10, &max, &min);
//	cout << "Max:" << max << endl;
//	cout << "Min:" << min << endl;
//}
#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char* name = new char[60];
//	strcpy(name, "������");
//	cout << name << endl;
//	delete[] name;
//	return 0;
//}
#include<iostream>
using namespace std;
void f(int(&a)[10], int n, int& max, int& min)
{
	max = min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])max = a[i];
		if (min > a[i])min = a[i];
	}
}
void main()
{
	int a[10] = { 2,5,3,9,0,8,1,7,6,4 };
	int max, min;
	f(a, 10, max, min);
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
}