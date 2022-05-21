#include <iostream>

using namespace std;

class A
{
public:
	A() { cout << "构造" << endl; }
	~A() { cout << "析构" << endl; }
};

int main()
{
	cout.fill('*');
	return 0;
}

//> 在长度 2N 的数组中找出重复 N 次的元素
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

//> 数组中重复的数字
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