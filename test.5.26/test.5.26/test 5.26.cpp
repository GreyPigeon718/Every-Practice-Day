//#include <stdio.h> 
//int main()
//{
//char a[10] = { '1','2','3','4','5','6','7','8','9',0 }, * p; int i;
//i = 8;
//p = a + i;
//printf("%s\n", p - 3);
//int arr[][3] = { {0,1,2},{2,2,2} };
//}
//�ַ������ҳ�����������ִ�
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	int count = 0, counted = 0;;
//	string s,m,k;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (isdigit(s[i]))
//		{
//			m += s[i];
//			count++;
//			if (count > counted)
//			{
//				k = m;
//				counted = count;
//			}
//		}
//		else
//		{
//			count = 0;
//			m = "";
//		}
//	}
//	if (count != 0)
//		cout << k << endl;
//	return 0;
//}
//�����г��ֳ�������һ�������
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int count = 0;
        int k = numbers.size() / 2;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] == numbers[k])
                count++;
        }
        if (count > k)
            return numbers[k];
        else
            return 0;
    }
};
