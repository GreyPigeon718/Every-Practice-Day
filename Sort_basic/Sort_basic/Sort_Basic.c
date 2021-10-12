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


// ��������������У�û��ʹ�ö���ĸ����ռ䣬�ռ临�Ӷȣ�O(1)
// ʱ�临�Ӷȣ�O(N^2)
// �ȶ��ԣ��ȶ�
void InsertSort(int array[], int size)
{
	// ע�⣺i��1��ʼ--->ԭ��
	for (int i = 1; i < size; ++i)   // ���ѭ�����ƣ��ж��ٸ�������Ҫ����size-1
	{
		// ����Ԫ�ز������
		int key = array[i];
		int end = i - 1;

		// �Ҵ�����Ԫ���������е�λ��
		// �������£���Ҫiλ��֮ǰ�����Ѳ����Ԫ������������а���--->O(N)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		// ����Ԫ��
		array[end + 1] = key;
	}
}


// ϣ������
// ʱ�临�Ӷȣ�O(N^1.25)~O(1.6N^1.25)
// �ռ临�Ӷȣ�O(1)
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		// gap/=2
		// gapÿ��ȡ����
		gap = gap / 3 + 1;  // kunth: 4 2 

		// ע�⣺i��1��ʼ--->ԭ��
		for (int i = gap; i < size; ++i)   // ���ѭ�����ƣ��ж��ٸ�������Ҫ����size-1
		{
			// ����Ԫ�ز������
			int key = array[i];
			int end = i - gap;

			// �Ҵ�����Ԫ���������е�λ��
			// �������£���Ҫiλ��֮ǰ�����Ѳ����Ԫ������������а���--->O(N)
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			// ����Ԫ��: ���뵽��ǰ�������һ��λ��
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

// ѡ������
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		// �ҵ�ǰ���������Ԫ�ص�λ��
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

// ѡ������
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1;  // [begin, end]
	while (begin < end)
	{
		// ��[begin, end]��������������С��Ԫ��
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

		// ������Ԫ�ز�����������λ��
		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);

		// ���endλ�ô洢�ĸպ�����С��Ԫ�أ�����Ľ����ͽ���С��Ԫ��λ�ø�����---maxPos
		// ��СԪ�ص�λ�÷����˸ı䣬�����Ҫ����minPos
		if (minPos == end)
			minPos = maxPos;

		// �����СԪ�ز���������ʼ��λ��
		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);

		++begin;
		--end;
	}
}

// ���µ���
void HeapAdjust(int array[], int size, int parent)
{
	// ��child���parent�ϴ�ĺ��ӣ�Ĭ���ȱ��parent������
	// �ȱ�����ӵ�ԭ���ǣ����parent�к��ӣ�parentһ�����������ӣ�Ȼ������Һ���
	int child = parent * 2 + 1;

	while (child < size)
	{
		// ��parent�нϴ�ĺ��ӣ���parent���Һ��ӱȽ�
		// �����ȱ�֤parent���Һ��Ӵ���
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		// ���parent�Ƿ�����ѵ�����
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



// ������
// ʱ�临�Ӷȣ�O(NlogN)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void HeapSort(int array[], int size)
{
	int end = size - 1;
	// 1. ����
	// ע��ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjust(array, size, root);  // ���µ���---ʱ�临�Ӷȣ�O(logN)

	// 2. ����--->���ö�ɾ����˼���������
	while (end)
	{
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}
}


// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�
void BubbleSort(int array[], int size)
{
	// ����ð�ݵ�����
	for (int i = 0; i < size - 1; ++i)  // -1��Ŀ���ǿ�����ðһ�ˣ���Ϊ���һ��ð��������ֻʣ��һ��Ԫ��
	{
		// ����ð�ݵķ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���
		/*
		// j����ʾǰһ��Ԫ�ص��±�
		for (int j = 0; j < size - i-1; ++j)  // -1Ŀ�ģ�j���ֻ��ȡ��ð������ĵ����ڶ���Ԫ��
		{
			if (array[j] > array[j + 1])
				Swap(&array[j], &array[j + 1]);
		}
		*/

		// j����ʾ��һ��Ԫ�ص��±꣬jҪȡ�����һ��Ԫ��
		for (int j = 1; j < size - i; ++j)  // -1Ŀ�ģ�j���ֻ��ȡ��ð������ĵ����ڶ���Ԫ��
		{
			if (array[j - 1] > array[j])
				Swap(&array[j], &array[j - 1]);
		}
	}
}

void BubbleSortOP(int array[], int size)
{
	int flag = 0;
	// ����ð�ݵ�����
	for (int i = 0; i < size - 1; ++i)  // -1��Ŀ���ǿ�����ðһ�ˣ���Ϊ���һ��ð��������ֻʣ��һ��Ԫ��
	{
		// ����ð�ݵķ�ʽ��������λ�õ�Ԫ�ؽ��бȽϣ�����������������ͽ��н���
		// j����ʾ��һ��Ԫ�ص��±꣬jҪȡ�����һ��Ԫ��
		flag = 0;  // ����ð�ݻ�û�бȽϣ���˽�falg����Ϊ0
		for (int j = 1; j < size - i; ++j)  // -1Ŀ�ģ�j���ֻ��ȡ��ð������ĵ����ڶ���Ԫ��
		{
			if (array[j - 1] > array[j])
			{
				Swap(&array[j], &array[j - 1]);
				flag = 1;  // �ڸ���ð��ʱ���仹����
			}
		}

		if (!flag)
			return;
	}
}

// ����ȡ�з�����������ȡ���м��������Ϊ��׼ֵ
int GetMiddleIndex(int array[], int left, int right)
{
	int mid = left + ((right - left) >> 1);

	// �������ݣ�left��mid��right-1
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

// hore���������˼��Ĵ��������
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
		// ��begin��ǰ�����ң��ұȻ�׼ֵ���Ԫ�أ��ҵ��˾�ͣ����
		while (begin < end && array[begin] <= key)
			begin++;


		// ��end�Ӻ���ǰ�ң��ұȻ�׼ֵС��Ԫ�أ��ҵ��˾�ͣ����
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
		// endλ���γ���һ���µĿ�
		// ��begin��ǰ�����ұȻ�׼ֵ���Ԫ��
		while (begin < end && array[begin] <= key)
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

	// ��������ȡ�з�����ȡ�����Ƶĸ���
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


// [left, right)��ʾ������Ԫ�ص�����
void QuickSort(int array[], int left, int right)
{
	if (right - left < 16)
	{
		// [left, right)�����������ٵ�һ���̶ȣ�ʹ�ò����������Ż�
		InsertSort(array + left, right - left);
	}
	else
	{
		// Partion���ջ�׼ֵ(���������е�ĳ��Ԫ��)��������л��ֳ������֣�������Ԫ�رȻ�׼ֵС���Ҳಿ�ֱȻ�׼ֵ��
		// �ú������ػ�׼ֵ�������е�λ��
		// [left, right) �����еĻ�׼ֵλ���Ѿ���ź��ˣ���׼ֵ���ͻ�׼ֵ�Ҳ಻һ������
		int div = Partion3(array, left, right);

		// ��׼ֵ����ࣺ[left, div)
		QuickSort(array, left, div);

		// ��׼ֵ���Ҳࣺ[div+1, right)
		QuickSort(array, div + 1, right);
	}
}


// ��ջ�����ݹ�ת��Ϊѭ��
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
		// �Ȱ��ջ�׼ֵ�����л���
		left = StackTop(&s);
		StackPop(&s);

		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion2(array, left, right);

			// �Ż�׼ֵ������--���Ұ벿�ֵ�������ջ[div+1, right)
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// �Ż�׼ֵ���Ұ��--����벿�ֵ�������ջ[left, div)
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}

	StackDestroy(&s);
}


// ʱ�临�Ӷȣ�O(N)
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

	// [left, mid)�����е����ݻ�û�а�����
	while (index1 < mid)
	{
		temp[index++] = array[index1++];
	}

	// [mid, right)�����е����ݻ�û�а�����
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

		// ��[left, mid)��[mid, right)����������й鲢
		MergeData(array, left, mid, right, temp);

		// �鲢��֮�������������temp,��temp������Ľ��������ԭ������
		memcpy(array + left, temp + left, (right - left) * sizeof(array[left]));
	}
}


// �ȶ��ԣ��ȶ���
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

			// [left, mid) �� [mid, right)ÿ����������gap
			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, size * sizeof(array[0]));
		gap *= 2;
	}

	free(temp);
}

// ��������---�볲ԭ��
// ʱ�临�Ӷȣ�O(N)  N: ��ʾԪ�صĸ���
// �ռ临�Ӷȣ�O(M)  M:��ʾ���ݷ�Χ�а������ݵ�����ĸ���
// �ȶ��ԣ� �ȶ�
// �����������ܼ�������ĳ����Χ��
void CountSort(int array[], int size)
{
	// 1.�����ݷ�Χ--->O(N)
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > maxValue)
			maxValue = array[i];

		if (array[i] < minValue)
			minValue = array[i];
	}

	// 2.�������������Ŀռ������maxValue-minValue+1, ����������������Ŀռ�
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(range * sizeof(int));
	memset(temp, 0, sizeof(int) * range);

	// 3. ͳ��������ÿ��Ԫ�س��ֵĸ���--->O(N)
	for (int i = 0; i < size; ++i)
		temp[array[i] - minValue]++;

	// 4. ����: ���ռ��������±��С������л���--->O(N)
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