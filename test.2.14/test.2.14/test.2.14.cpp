// Ѱ�ҷ�ֵ

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;
        // һֱ��֤[left, right]�н�
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // mid��mid+1���бȽϣ����ж����µķ���
            // ���mid+1��˵�����ں���
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            // mid�󣬷���ǰ��
            else
                right = mid;
        }
        // �˳���������left == right��ʱ��[left, right]�з壬�����right
        return right;
    }
};