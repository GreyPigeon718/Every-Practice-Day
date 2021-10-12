#include "Sort_Basic.h"
#include <stdio.h>
#include "Stack.h"
#include <malloc.h>
#include <string.h>





void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}


// 在整个排序过程中，没有使用额外的辅助空间，空间复杂度：O(1)
// 时间复杂度：O(N^2)
// 稳定性：稳定
void InsertSort(int array[], int size)
{
	// 注意：i从1开始--->原因：
	for (int i = 1; i < size; ++i)   // 外层循环控制：有多少个数据需要插入size-1
	{
		// 单个元素插入过程
		int key = array[i];
		int end = i - 1;

		// 找待插入元素在区间中的位置
		// 最差情况下：需要i位置之前所有已插入的元素整体往后进行搬移--->O(N)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		// 插入元素
		array[end + 1] = key;
	}
}


// 希尔排序
// 时间复杂度：O(N^1.25)~O(1.6N^1.25)
// 空间复杂度：O(1)
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		// gap/=2
		// gap每次取素数
		gap = gap / 3 + 1;  // kunth: 4 2 

		// 注意：i从1开始--->原因：
		for (int i = gap; i < size; ++i)   // 外层循环控制：有多少个数据需要插入size-1
		{
			// 单个元素插入过程
			int key = array[i];
			int end = i - gap;

			// 找待插入元素在区间中的位置
			// 最差情况下：需要i位置之前所有已插入的元素整体往后进行搬移--->O(N)
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			// 插入元素: 插入到当前分组的下一个位置
			array[end + gap] = key;
		}

		//gap--;
	}
}

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// 选择排序
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：不稳定
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		// 找当前区间中最大元素的位置
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

// 选择排序
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1;  // [begin, end]
	while (begin < end)
	{
		// 在[begin, end]区间中找最大和最小的元素
		int maxPos = begin, minPos = begin;
		int j = begin + 1;

		while (j <= end)
		{
			if (array[j] > array[maxPos])
				maxPos = j;

			if (array[j] < array[minPos])
				minPos = j;

			++j;
		}

		// 如果最大元素不在区间最后的位置
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);

		// 如果end位置存储的刚好是最小的元素，上面的交换就将最小的元素位置更改了---maxPos
		// 最小元素的位置发生了改变，则必须要更新minPos
		if (minPos == end)
			minPos = maxPos;

		// 如果最小元素不在区间起始的位置
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);

		++begin;
		--end;
	}
}

// 向下调整
void HeapAdjust(int array[], int size, int parent)
{
	// 用child标记parent较大的孩子，默认先标记parent的左孩子
	// 先标记左孩子的原因是：如果parent有孩子，parent一定是先有左孩子，然后才有右孩子
	int child = parent * 2 + 1;

	while (child < size)
	{
		// 找parent中较大的孩子：用parent左右孩子比较
		// 必须先保证parent的右孩子存在
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		// 检测parent是否满足堆的性质
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}



// 堆排序
// 时间复杂度：O(NlogN)
// 空间复杂度：O(1)
// 稳定性：不稳定
void HeapSort(int array[], int size)
{
	int end = size - 1;
	// 1. 建堆
	// 注意从倒数第一个非叶子节点的位置开始使用堆调整，一直调整到根节点的位置
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjust(array, size, root);  // 向下调整---时间复杂度：O(logN)

	// 2. 排序--->利用堆删除的思想进行排序
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}


// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：稳定
void BubbleSort(int array[], int size)
{
	// 控制冒泡的趟数
	for (int i = 0; i < size - 1; ++i)  // -1的目的是可以少冒一趟，因为最后一次冒泡区间中只剩余一个元素
	{
		// 具体冒泡的方式：用相邻位置的元素进行比较，如果不满足条件，就进行交换
		/*
		// j：表示前一个元素的下标
		for (int j = 0; j < size - i-1; ++j)  // -1目的：j最多只能取到冒泡区间的倒数第二个元素
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
		*/

		// j：表示后一个元素的下标，j要取到最后一个元素
		for (int j = 1; j < size - i; ++j)  // -1目的：j最多只能取到冒泡区间的倒数第二个元素
		{
			if (array[j - 1] > array[j])
				Swap(&array[j], &array[j - 1]);
		}
	}
}

void BubbleSortOP(int array[], int size)
{
	int flag = 0;
	// 控制冒泡的趟数
	for (int i = 0; i < size - 1; ++i)  // -1的目的是可以少冒一趟，因为最后一次冒泡区间中只剩余一个元素
	{
		// 具体冒泡的方式：用相邻位置的元素进行比较，如果不满足条件，就进行交换
		// j：表示后一个元素的下标，j要取到最后一个元素
		flag = 0;  // 该趟冒泡还没有比较，因此将falg设置为0
		for (int j = 1; j < size - i; ++j)  // -1目的：j最多只能取到冒泡区间的倒数第二个元素
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j], &array[j - 1]);
				flag = 1;  // 在该趟冒泡时区间还无序
			}
		}

		if (!flag)
			return;
	}
}

// 三数取中法：三个数据取最中间的数据作为基准值
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);

	// 三个数据：left、mid、right-1
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

// hore：提出快排思想的大佬提出的
int Partion1(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int keyofindex = GetMiddleIndex(array, left, right);
	int key;
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);

	key = array[right - 1];

	while (begin < end)
	{
		// 让begin从前往后找，找比基准值大的元素，找到了就停下来
		while (begin < end && array[begin] <= key)
			begin++;


		// 让end从后往前找，找比基准值小的元素，找到了就停下来
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
			Swap(&array[begin], &array[end]);
	}

	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

int Partion2(int array[], int left, int right)
{
	int begin = left;
	int end = right - 1;
	int keyofindex = GetMiddleIndex(array, left, right);
	int key;
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);

	key = array[right - 1];

	while (begin < end)
	{
		// end位置形成了一个新的坑
		// 让begin从前往后找比基准值大的元素
		while (begin < end && array[begin] <= key)
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

	// 采用三数取中法降低取到机制的概率
	int keyofindex = GetMiddleIndex(array, left, right);
	int key;
	if (keyofindex != right - 1)
		Swap(&array[keyofindex], &array[right - 1]);

	key = array[right - 1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		++cur;
	}

	if (++prev != right - 1)
		Swap(&array[right - 1], &array[prev]);

	return prev;
}


// [left, right)表示待排序元素的区间
void QuickSort(int array[], int left, int right)
{
	if (right - left < 16)
	{
		// [left, right)区间中数据少到一定程度，使用插入排序来优化
		InsertSort(array + left, right - left);
	}
	else
	{
		// Partion按照基准值(就是区间中的某个元素)对区间进行划分成两部分，作部分元素比基准值小，右侧部分比基准值大
		// 该函数返回基准值在区间中的位置
		// [left, right) 区间中的基准值位置已经存放好了，基准值左侧和基准值右侧不一定有序
		int div = Partion3(array, left, right);

		// 基准值的左侧：[left, div)
		QuickSort(array, left, div);

		// 基准值的右侧：[div+1, right)
		QuickSort(array, div + 1, right);
	}
}


// 用栈来将递归转换为循环
void QuickSortNor(int array[], int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);

	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		// 先按照基准值来进行划分
		left = StackTop(&s);
		StackPop(&s);

		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion2(array, left, right);

			// 排基准值的左半侧--将右半部分的区间入栈[div+1, right)
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// 排基准值的右半侧--将左半部分的区间入栈[left, div)
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}

	StackDestroy(&s);
}


// 时间复杂度：O(N)
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index1 = left, index2 = mid, index = left;
	while (index1 < mid && index2 < right)
	{
		if (array[index1] <= array[index2])
			temp[index++] = array[index1++];
		else
			temp[index++] = array[index2++];
	}

	// [left, mid)区间中的数据还没有搬移完
	while (index1 < mid)
	{
		temp[index++] = array[index1++];
	}

	// [mid, right)区间中的数据还没有搬移完
	while (index2 < right)
	{
		temp[index++] = array[index2++];
	}
}

void _MergeSort(int array[], int left, int right, int temp[])
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);

		// [left, mid)
		_MergeSort(array, left, mid, temp);

		// [mid, right)
		_MergeSort(array, mid, right, temp);

		// 将[left, mid)和[mid, right)有序区间进行归并
		MergeData(array, left, mid, right, temp);

		// 归并好之后，有序的数据在temp,将temp中有序的结果拷贝到原数组中
		memcpy(array + left, temp + left, (right - left) * sizeof(array[left]));
	}
}


// 稳定性：稳定的
void MergeSort(int array[], int size)
{
	int* temp = (int*)malloc(size * sizeof(array[0]));
	if (NULL == temp)
		return;

	_MergeSort(array, 0, size, temp);

	free(temp);
}

void MergeSortNor(int array[], int size)
{
	int gap = 1;
	int* temp = (int*)malloc(size * array[0]);
	if (NULL == temp)
		return;

	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid > size)
				mid = size;

			if (right > size)
				right = size;

			// [left, mid) 和 [mid, right)每个分组中有gap
			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, size * sizeof(array[0]));
		gap *= 2;
	}

	free(temp);
}

// 计数排序---鸽巢原理
// 时间复杂度：O(N)  N: 表示元素的个数
// 空间复杂度：O(M)  M:表示数据范围中包含数据的种类的个数
// 稳定性： 稳定
// 场景：数据密集集中在某个范围中
void CountSort(int array[], int size)
{
	// 1.找数据范围--->O(N)
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > maxValue)
			maxValue = array[i];

		if (array[i] < minValue)
			minValue = array[i];
	}

	// 2.计算用来计数的空间个数：maxValue-minValue+1, 申请用来保存计数的空间
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(range * sizeof(int));
	memset(temp, 0, sizeof(int) * range);

	// 3. 统计区间中每个元素出现的个数--->O(N)
	for (int i = 0; i < size; ++i)
		temp[array[i] - minValue]++;

	// 4. 回收: 按照计数数组下标从小到大进行回收--->O(N)
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (temp[i]--)
		{
			array[index++] = i + minValue;
		}
	}

	free(temp);
}

/////////////////////////////////////////////////////////
void TestSort()
{
	// int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	// int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	//int array[] = { 4, 1, 7, 6, 3, 9, 2, 8, 0, 5 };

	int array[] = { 3,2,1,8,0,4,5,4,6,7,0,9,1,3,5,7,8,5,4,3,2 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	// InsertSort(array, sizeof(array) / sizeof(array[0]));
	// ShellSort(array, sizeof(array) / sizeof(array[0]));
	// SelectSort(array, sizeof(array) / sizeof(array[0]));
	// SelectSortOP(array, sizeof(array) / sizeof(array[0]));
	// HeapSort(array, sizeof(array) / sizeof(array[0]));
	// BubbleSort(array, sizeof(array) / sizeof(array[0]));
	// BubbleSortOP(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, 0, sizeof(array) / sizeof(array[0]));

	// QuickSortNor(array, sizeof(array) / sizeof(array[0]));
	// MergeSort(array, sizeof(array) / sizeof(array[0]));
	// MergeSortNor(array, sizeof(array) / sizeof(array[0]));
	CountSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}