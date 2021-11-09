#include <iostream>
#include <vector>
using namespace std;
template<class T>
void swap(T* x, T* y)
{
    T tmp = *x;
    *x = *y;
    *y = tmp;
}
//hore
int partion(int arr[], int left, int right)
{
    int begin = left;
    int end = right - 1;
    int key = arr[right - 1];

    while (begin < end)
    {
        while (begin < end && arr[begin] <= key)
            begin++;

        while (begin < end && arr[end] >= key)
            end--;

        swap(&arr[begin], &arr[end]);
    }
    if (begin != right - 1)
        swap(&arr[begin], &arr[right - 1]);

    return begin;
}
//挖坑法
int partion2(int arr[], int left, int right)
{
    int begin = left;
    int end = right - 1;
    int key = arr[right - 1];
    
    while (begin < end)
    {
        while (begin < end && arr[begin] <= key)
            begin++;

        if (begin < end)
        {
            arr[end] = arr[begin];
            end--;
        }

        while (begin < end && arr[end] >= key)
            end--;
        
        if (begin < end)
        {
            arr[begin] = arr[end];
            begin++;
        }
    }
    arr[begin] = key;
    return begin;
}
// 双指针
int partion3(int arr[], int left, int right)
{
    int cur = left;
    int prev = left - 1;
    int key = arr[right - 1];

    while (cur < right)
    {
        // 只要进行交换，就说明前面的元素都满足要求
        if (arr[cur] < key && ++prev != cur)
            swap(&arr[cur], &arr[prev]);
        cur++;
    }
    if (++prev != right - 1)
        swap(&arr[prev], &arr[right - 1]);
    return prev;
}
void QuickSort(int arr[], int left, int right)
{
    if (right - left > 1)
    {
        int div = partion3(arr, left, right);

        QuickSort(arr, left, div);

        QuickSort(arr, div + 1, right);
    }
}
void Print(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}
int main()
{
    int array[] = { 3,5,7,9,1,6,4,0,2,8 };
    QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
    Print(array, sizeof(array) / sizeof(array[0]));
    return 0;
}
//四方平方和定理
class Solution {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};