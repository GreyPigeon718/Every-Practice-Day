// 有序数组中的单一元素
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid 分奇数和偶数，奇数时mid和mid+1的值相等，则
            // 单一元素在mid的前面
            if (mid % 2 == 0)
            {
                // 偶数时，判断mid和mid+1的值，相等，则元素在mid之前
                if (mid + 1 < nums.size() - 1 && nums[mid] == nums[mid + 1])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
            {
                // 奇数时,判断mid和mid-1的值,相等，则元素在mid的之后
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[right];
    }
};

// 无重复字符的最长子串
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ms;
        int right = -1;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // 控制左指针，左指针代表子串起始位置
            // 每走一步，删除前面一个
            if (i != 0)
                ms.erase(s[i - 1]);
            // 在没有重复的情况下，右指针一直往后走，连续无重复子串
            while (right + 1 < s.size() && ms.count(s[right + 1]) != 1)
            {
                ms.insert(s[right + 1]);
                right++;
            }
            // 右指针-左指针+1 判断最长连续无重复子串
            res = max(res, right - i + 1);
        }
        return res;
    }
};