#include<iostream>
using namespace std;

template<class T>
void swap(T* a, T* b)
{
	T c = *a;
	*a = *b;
	*b = c;
}
int Partion1(int array[], int left, int right)
{
    int begin = left;
    int end = right - 1;
    int key = array[right - 1];

    while (begin < end)
    {
        while (begin < end && array[begin] <= key)
            begin++;

        while (begin < end && array[end] >= key)
            end--;

        if (begin < end)
            swap(&array[begin], &array[end]);
    }
    if (begin != right - 1)
        swap(&array[begin], &array[right - 1]);
    return begin;
}
int Partion2(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin < end)
	{
		while (begin < end && array[begin] >= key)
			begin++;
		// ��beginλ�ô��Ԫ����endλ�õĿ�
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}


		// beginλ���γ���һ���µĿ�
		// ��end�Ӻ���ǰ�ұȻ�׼ֵС��Ԫ�أ���beginλ�õĿ�
		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

		// �û�׼ֵ������һ����
		array[begin] = key;
		return begin;
}
int Partion3(int array[], int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key;

	key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			swap(&array[cur], &array[prev]);

		++cur;
	}

	if (++prev != right - 1)
		swap(&array[right - 1], &array[prev]);

	return prev;
}
void QuickSort(int array[], int left, int right)
{
	// if (right - left < 1)
	// {
	// 	// [left, right)�����������ٵ�һ���̶ȣ�ʹ�ò����������Ż�
	// 	InsertSort(array + left, right - left);
	// }
	// else
	// {
		// Partion���ջ�׼ֵ(���������е�ĳ��Ԫ��)��������л��ֳ������֣�������Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
		// �ú������ػ�׼ֵ�������е�λ��
		// [left, right) �����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ���ͻ�׼ֵ�Ҳ಻һ������
	if (right - left > 1)
	{
		int div = Partion2(array, left, right);

		// ��׼ֵ����ࣺ[left, div)
		QuickSort(array, left, div);

		// ��׼ֵ���Ҳࣺ[div+1, right)
		QuickSort(array, div + 1, right);
	}
	//  }
}
//
int main()
{
	int array[] = { 1,5,6,9,7,2 };
	QuickSort(array, 0, (sizeof(array) / sizeof(array[0])));

}

