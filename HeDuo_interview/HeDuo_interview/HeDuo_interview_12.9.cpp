// 32位数 1的个数
#include <iostream>

using namespace std;

int Bin_Num_count(int x)
{
	int n = x;
	int count = 0;
	while (n)
	{
		n &= n - 1;
		count++;
	}
	return count;
}
//int main()
//{
//	int a = 1024;
//	cout << Bin_Num_count(a-1) << endl;
//	return 0;
//}
// 爬楼梯 一次走一个台阶或者两个台阶 高度n个台阶

int Floor_n(int n)
{
	int a = 0, b = 0;
	int c = 1;
	for (int i = 1; i <= n; ++i)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}
int main()
{
	int x = 4;
	cout << Floor_n(x);
}
// 判断一个单项链表是否有环

bool ListNode_cirle(ListNode* root)
{
	if (root == nullptr)
		return false;
	ListNode * slow = root;
	ListNode* quick = root->next;
	while (quick->next || quick)
	{
		quick = quick->next->next;
		slow = slow->next;
		if (quick->val == slow->val)
			return true;
	}
	return false;
}