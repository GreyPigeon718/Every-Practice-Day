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
//统计每个月兔子总数
//#include <iostream>
//
//using namespace std;
//
//int getNum(int n)
//{
//	int ret, f1 = 1, f2 = 1; //前两个月都是一只
//	for (int i = 3; i <= n; ++i) //从第三个月开始到第n月
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
//扑克牌顺子
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
getLuckyPacket:从当前位置开始搜索符合要求的组合，一直搜索到最后一个位置结束
x[]: 袋子中的所有球
n: 球的总数
pos: 当前搜索的位置
sum: 到目前位置的累加和
multi: 到目前位置的累积值
*/
int getLuckyPacket(int x[], int n, int pos, int sum, int multi) {
	int count = 0;
	//循环，搜索以位置i开始所有可能的组合 
	for (int i = pos; i < n; i++) {
		sum += x[i];
		multi *= x[i];
		if (sum > multi) {
			//找到符合要求的组合，加1，继续累加后续的值，看是否有符合要求的集合 
			count += 1 + getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else if (x[i] == 1) {
			//如何不符合要求，且当前元素值为1，则继续向后搜索 
			count += getLuckyPacket(x, n, i + 1, sum, multi);
		}
		else {
			//如何sum大于multi,则后面就没有符合要求的组合了 
			break;
		}
		//要搜索下一个位置之前，首先恢复sum和multi 
		sum -= x[i];
		multi /= x[i];
		//数字相同的球，没有什么区别，都只能算一个组合，所以直接跳过 
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
		//从第一个位置开始搜索 
		cout << getLuckyPacket(x, n, 0, 0, 1) << endl;
	}
	return 0;
}