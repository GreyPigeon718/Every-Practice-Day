//> ��ҽ��� II
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end)
    {
        int first = nums[start];
        //> �տ�ʼ��ʱ���൱���������ӣ�ѡ�����
        int second = max(nums[start], nums[start + 1]);
        //> �ӵ�������ʼ��������
        for (int i = start + 2; i <= end; ++i)
        {
            int temp = second;
            // ��͵��͵��Ǯ���Ƚ�
            second = max(second, nums[i] + first);
            first = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        //> ֻ��һ������
        if (nums.size() == 1)
            return nums[0];
        //> ֻ����������
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        // ��Ϊ���ڵķ���ȡ������������Ҫ���Σ�������ȫ��
        return max(robRange(nums, 0, nums.size() - 2), robRange(nums, 1, nums.size() - 1));
    }
};

class Solution1 {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        }
        else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};
//> ��Ծ��Ϸ
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
                return false;
            //> k��ʾ���Ե�����Զ��λ��
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
