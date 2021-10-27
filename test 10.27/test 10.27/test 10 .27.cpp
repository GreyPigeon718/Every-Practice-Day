//双指针

//移动零

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n)
        {
            if (nums[right])
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
//输入有序数组
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int>  v;
        while ((numbers[left] + numbers[right]) != target)
        {
            if ((numbers[left] + numbers[right]) > target)
                right--;
            else if (numbers[left] + numbers[right] < target)
                left++;
        }
        v.push_back(left + 1);
        v.push_back(right + 1);
        return  v;
    }
};

//数据库连接池
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
    int x;
    while (cin >> x)
    {
        int count = 0;
        int max_count = 0;
        string id;
        string action;
        while (x--)
        {
            cin >> id >> action;
            if (action == "connect")
                count++;
            if (action == "disconnect")
                count--;
            if (count > max_count)
                max_count = count;
        }
        cout << max_count << endl;
    }
    return 0;
}