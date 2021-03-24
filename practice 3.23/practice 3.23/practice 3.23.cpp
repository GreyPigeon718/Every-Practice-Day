//(4)模仿教材中【例1.11】的程序，编写一个C++程序，使用new开辟动态存储单
//元保存你的名字，并显示出你的名字，输出完毕后使用delete释放动态存储单元。
//(5)阅读下面的程序，将其中的指针函数参数修改为引用作为参数。
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
//	strcpy(name, "王红乔");
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