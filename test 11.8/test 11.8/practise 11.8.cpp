#include <iostream>
#include <vector>
using namespace std;

int partion(int* q, int start2, int end2)
{
	int start = start2;
	int end = end2 - 1;
	int key = 
	int* p = q;
	while (start < end)
	{
		while (start < end && *(p + start) <= key)
			start++;
		
		while (start < end && *(p + end) >= key)
			end--;

		swap((p + start), (p + end));
	}
	if (start != end - 1)
		swap((p + start), (p + end2 - 1));
	return *(p + start);
}
void QuickSort(int* p, int left, int right)
{
	printf("1");
	if (right - left > 1)
	{
		int div = partion(p, left, right);

		QuickSort(p, left, div);

		QuickSort(p, div + 1, right);
	}
}
int main()
{
	vector<int> v { 1, 3, 5, 9, 8, 6, 2, 4, 7 };
	QuickSort(v, 0 , sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr); ++i)
		printf("%d ", arr[i]);
}