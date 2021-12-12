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
		// 让begin位置大的元素填end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}


		// begin位置形成了一个新的坑
		// 让end从后往前找比基准值小的元素，填begin位置的坑
		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

		// 用基准值填最后的一个坑
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
	// 	// [left, right)区间中数据少到一定程度，使用插入排序来优化
	// 	InsertSort(array + left, right - left);
	// }
	// else
	// {
		// Partion按照基准值(就是区间中的某个元素)对区间进行划分成两部分，作部分元素比基准值小，右侧部分比基准值大
		// 该函数返回基准值在区间中的位置
		// [left, right) 区间中的基准值位置已经存放好了，基准值左侧和基准值右侧不一定有序
	if (right - left > 1)
	{
		int div = Partion2(array, left, right);

		// 基准值的左侧：[left, div)
		QuickSort(array, left, div);

		// 基准值的右侧：[div+1, right)
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

