// 32λ�� 1�ĸ���
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
// ��¥�� һ����һ��̨�׻�������̨�� �߶�n��̨��

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
// �ж�һ�����������Ƿ��л�

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