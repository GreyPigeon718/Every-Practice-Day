#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> mp;
	for (int i = 0; i < s.size(); ++i)
	{
		mp[s[i]]++;
	}
	map<char, int> ::iterator iter;
	for (iter = mp.begin(); iter != mp.end(); ++iter)
	{
		cout << iter->first << ": " << iter->second << " " << endl;
	}
	return 0;
}

// 统计字符串中不同的字符出现的频率



void InsertSort(int* a, int length)
{
	for (int i = 1; i < length; ++i)
	{
		int x = a[i];
		int j = i - 1;
		while (j > 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

//int main()
//{
//	int arr[] = { 2,5,9,7,9 };
//	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
//	{
//		cout << arr[i] << " ";
//	}
//	return 0;
//}