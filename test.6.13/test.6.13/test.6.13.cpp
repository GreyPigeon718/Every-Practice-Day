//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    void print()
//    {
//        cout << "A:print()";
//    }
//};
//class B : private A
//{
//public:
//    void print()
//    {
//        cout << "B:print()";
//    }
//};
//class C : public B
//{
//public:
//    void print()
//    {
//        A::print();
//    }
//};
//int main()
//{
//    C b;
//    b.print();
//}
//ͳ��ÿ������������
//#include <iostream>
//
//using namespace std;
//
//int getNum(int n)
//{
//	int ret, f1 = 1, f2 = 1; //ǰ�����¶���һֻ
//	for (int i = 3; i <= n; ++i) //�ӵ������¿�ʼ����n��
//	{
//		ret = f1 + f2;
//		f1 = f2;
//		f2 = ret;
//	}
//	return ret;
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//		cout << getNum(n) << endl;
//	return 0;
//}
//�˿���˳��
//class Solution {
//public:
//    bool IsContinuous(vector<int> numbers) {
//        int length = numbers.size();
//        sort(numbers.begin(), numbers.end(), less<int>());
//        int numzero = 0;
//        int numblank = 0;
//        for (int i = 0; i < length; ++i)
//            if (numbers[i] == 0)
//                ++numzero;
//        int small = numzero;
//        int big = small + 1;
//        while (big < length)
//        {
//            if (numbers[small] == numbers[big])
//                return false;
//            numblank += numbers[big] - numbers[small] - 1;
//            small = big;
//            ++big;
//        }
//        return numzero >= numblank ? true : false;
//    }
//};
#include<iostream> 
#include<algorithm> 
using namespace std;

/*
getLuckyPacket:�ӵ�ǰλ�ÿ�ʼ��������Ҫ�����ϣ�һֱ���������һ��λ�ý���
x[]: �����е�������
n: �������
pos: ��ǰ������λ��
sum: ��Ŀǰλ�õ��ۼӺ�
multi: ��Ŀǰλ�õ��ۻ�ֵ
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
	int count = 0;
	//ѭ����������λ��i��ʼ���п��ܵ���� 
	for (int i = pos; i < n; i++) {
		sum += x[i];
		multi *= x[i];
		if (sum > multi) {
			//�ҵ�����Ҫ�����ϣ���1�������ۼӺ�����ֵ�����Ƿ��з���Ҫ��ļ��� 
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			//��β�����Ҫ���ҵ�ǰԪ��ֵΪ1�������������� 
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else {
			//���sum����multi,������û�з���Ҫ�������� 
			break;
		}
		//Ҫ������һ��λ��֮ǰ�����Ȼָ�sum��multi 
		sum -= x[i];
		multi /= x[i];
		//������ͬ����û��ʲô���𣬶�ֻ����һ����ϣ�����ֱ������ 
		while (i < n - 1 && x[i] == x[i + 1]) {
			i++;
		}
	}
	return count;
}
int main() {
	int n = 0;
	while (cin >> n) {
		int x[1000];
		//int* x = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		sort(x, x + n);
		//�ӵ�һ��λ�ÿ�ʼ���� 
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}