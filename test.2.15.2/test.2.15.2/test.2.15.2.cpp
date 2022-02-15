//>  �����е�������
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int row = matrix.size(); //> ��
        int col = matrix[0].size(); //> ��
        //>  һά����洢ÿһ�е����ֵ��ÿһ�е���Сֵ
        vector<int> col_max(col, 0), row_min(row, INT_MAX);
        //> ��ʼȡֵ
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                col_max[j] = max(col_max[j], matrix[i][j]);
                row_min[i] = min(row_min[i], matrix[i][j]);
            }
        }
        vector<int> ret;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                //> �����ȶԣ������������㱾����С���������
                if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j])
                    ret.push_back(matrix[i][j]);
            }
        }
        return ret;
    }
};

//> ɾ�����������е��ظ�Ԫ�� II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        //> ��Ϊ�п���ɾ��ͷ���������Ҫһ���ƽڵ�
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next && cur->next->next)
        {
            //> �жϳ�����ȵ�ֵʱ����ֵ��������,һһ���Ƚ�
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                //> ע�⣺�����﷨Ҫ��&&�ж�Ϊ��ʱ���Ͳ���ִ�к������
                //> һ��Ҫ��cur->next����ǰ�棬��֤�����ָ�����
                while (cur->next && x == cur->next->val)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};

//> ����֮��
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        //> ��һ��ѭ
        for (int first = 0; first < nums.size(); ++first)
        {
            //> �������һ�ε�ö�ٲ�ͬ���Ž���ö��
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int target = -nums[first];
            int third = nums.size() - 1;
            //> �ڶ���ѭ������Ҫ˫ָ��
            for (int second = first + 1; second < nums.size(); ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                //> ���ö�ٵĺʹ��ˣ�����third��ǰ�ߣ���֤second��third���н���
                while (third > second && nums[third] + nums[second] > target)
                    --third;
                //> ��third��second�غ�ʱ���ٲ����к�Ϊ��Ľ����
                if (third == second)
                    break;
                if (nums[second] + nums[third] == target)
                    vv.push_back({ nums[first],nums[second], nums[third] });
            }
        }
        return vv;
    }
};


