#include <iostream>
#include <vector>
//���һ���ӷ�����������ظ����ַ���
using namespace std;

int Length(string s)
{
	int begin = 0, int end = 0;
	int Max_length = -1;
	int size = s.size();
	while (end < size)
	{
		int length = 0;
		char c = s[end];
		for (int i = begin; i < size; ++i)
		{
			if (s[begin] == c)
			{
				begin = i + 1;
				length = end - begin;
				break;
			}
		}
		end++;
		length++;
		Max_length = max(length, Max_length);
	}
	return Max_length;
}