#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "����" << endl; }
	~A() { cout << "����" << endl; }
};

int main()
{
	cout.fill('*');
	return 0;
}

//> �ڳ��� 2N ���������ҳ��ظ� N �ε�Ԫ��
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int length = nums.size();
        unordered_map<int, int> ump;
        for (int i = 0; i < length; ++i)
        {
            ump[nums[i]]++;
            if (ump[nums[i]] > 1)
                return nums[i];
        }
        return -1;
    }
};

//> �������ظ�������
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int const& n : nums) {
            if (nums[abs(n)] < 0) return abs(n);
            nums[abs(n)] *= -1;
        }
        return 0;
    }
};