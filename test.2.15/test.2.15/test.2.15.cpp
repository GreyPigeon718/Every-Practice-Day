// ���������еĵ�һԪ��
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid ��������ż��������ʱmid��mid+1��ֵ��ȣ���
            // ��һԪ����mid��ǰ��
            if (mid % 2 == 0)
            {
                // ż��ʱ���ж�mid��mid+1��ֵ����ȣ���Ԫ����mid֮ǰ
                if (mid + 1 < nums.size() - 1 && nums[mid] == nums[mid + 1])
                    left = mid + 1;
                else
                    right = mid;
            }
            else
            {
                // ����ʱ,�ж�mid��mid-1��ֵ,��ȣ���Ԫ����mid��֮��
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return nums[right];
    }
};

// ���ظ��ַ�����Ӵ�
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ms;
        int right = -1;
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // ������ָ�룬��ָ������Ӵ���ʼλ��
            // ÿ��һ����ɾ��ǰ��һ��
            if (i != 0)
                ms.erase(s[i - 1]);
            // ��û���ظ�������£���ָ��һֱ�����ߣ��������ظ��Ӵ�
            while (right + 1 < s.size() && ms.count(s[right + 1]) != 1)
            {
                ms.insert(s[right + 1]);
                right++;
            }
            // ��ָ��-��ָ��+1 �ж���������ظ��Ӵ�
            res = max(res, right - i + 1);
        }
        return res;
    }
};