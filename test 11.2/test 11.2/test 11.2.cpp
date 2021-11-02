//删除表中节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    void deleteNode(ListNode* node) {
//        ListNode* tmp = node->next;
//        node->val = tmp->val;
//        node->next = tmp->next;
//    }
//};


#include <iostream>
using namespace std;
template<class T>
void swap(T* a, T* b)
{
    T c = *a;
    *a = *b;
    *b = c;
}
//hore
int partion1(int array[], int left, int right)
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
//双指针
int partion2(int array[], int left, int right)
{
    int begin = left;
    int end = right - 1;
    int key = array[right - 1];

    while (begin < end)
    {
        while (begin < end && array[begin] <= key)
            begin++;

        if (begin < end)
        {
            array[end] = array[begin];
            end--;
        }

        while (begin < end && array[end] >= key)
            end--;

        if (begin < end)
        {
            array[begin] = array[end];
            begin++;
        }
    }
    array[begin] = key;
    return begin;
}
//双指针

int partion3(int array[], int left, int right)
{
    int cur = left;
    int prev = cur - 1;
    int key = array[right - 1];
    while (cur < right)
    {
        if (array[cur] < key && ++prev != cur)
            swap(&array[cur], &array[prev]);
        cur++;
    }
    if (++prev != right - 1)
        swap(&array[prev], &array[right - 1]);
    return prev;
    
}
void  QuickSort(int array[], int left, int right)
{
    if (right - left > 1)
    {
        int div = partion3(array, left, right);

        QuickSort(array, left, div);

        QuickSort(array, div + 1, right);
        
    }
}
void Print(int array[], int length)
{
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";
}
int main()
{
    int array[] = { 3,5,7,9,1,6,4,0,2,8 };
    QuickSort(array, 0, sizeof(array) / sizeof(array[0]));
    Print(array, sizeof(array) / sizeof(array[0]));
    return 0;
}