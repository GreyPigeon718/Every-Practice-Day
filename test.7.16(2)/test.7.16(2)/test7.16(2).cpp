//���ջά��
//#include<iostream>
//#include<cmath>
//using namespace std;
////1.���ʣ�n����ȡ���Ĳ����Լ����ֵ����и���/n���˿��ܳ�ȡ�����п�����
//long long NotSelf(int n)//n����ȡ�����Լ����ֵĿ�����
//{
//    if (n == 1)
//        return 0;
//    if (n == 2)
//        return 1;
//    return (n - 1) * (NotSelf(n - 1)/*��һ�������������ȡ�����ض��˵�����*/
//        + NotSelf(n - 2)/*�ڶ���������ض��˺ͱ�ѡ�����໥�õ��Է�������*/);
//}
//long long Count(int n)
//{
//    double m = 1;
//    for (int i = 2; i <= n; ++i)//n�Ľ׳�
//        m *= i;
//    return m;
//}
//
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        double ret = (double)NotSelf(n) / Count(n);         //�������
//        printf("%2.2f%%\n", ret * 100);
//    }
//    return 0;
//}
//�����б�
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> str;
		size_t pos = 0;
		while (pos < s.size())
		{
			if (s[pos] == '\"')
			{
				size_t end = s.find('\"', pos + 1);
				str.push_back(s.substr(pos + 1, end - pos - 1));//��˫����ȥ��
				pos = end + 2;//���ź�˫����
			}
			else
			{
				size_t end = s.find(',', pos + 1);
				if (end == -1)
				{
					str.push_back(s.substr(pos, s.size() - pos));
					break;
				}
				str.push_back(s.substr(pos, end - pos));
				pos = end + 1;
			}
		}
		getline(cin, s);
		if (str.end() == find(str.begin(), str.end(), s))
			cout << "Important!" << endl;
		else
			cout << "Ignore" << endl;
	}
	return 0;
}