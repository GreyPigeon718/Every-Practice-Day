//>  矩阵中的幸运数
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int row = matrix.size(); //> 行
        int col = matrix[0].size(); //> 列
        //>  一维数组存储每一列的最大值和每一行的最小值
        vector<int> col_max(col, 0), row_min(row, INT_MAX);
        //> 开始取值
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
                //> 用来比对，幸运数需满足本行最小，本列最大
                if (matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j])
                    ret.push_back(matrix[i][j]);
            }
        }
        return ret;
    }
};

//> 删除排序链表中的重复元素 II
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
        //> 因为有可能删除头结点所以需要一个哑节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next && cur->next->next)
        {
            //> 判断出现相等的值时，把值保存下来,一一做比较
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                //> 注意：按照语法要求，&&判断为假时，就不会执行后续语句
                //> 一定要将cur->next放在前面，保证不会空指针访问
                while (cur->next && x == cur->next->val)
                    cur->next = cur->next->next;
            }
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};

//> 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        //> 第一层循
        for (int first = 0; first < nums.size(); ++first)
        {
            //> 必须和上一次的枚举不同，才进行枚举
            if (first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }
            int target = -nums[first];
            int third = nums.size() - 1;
            //> 第二层循环，需要双指针
            for (int second = first + 1; second < nums.size(); ++second)
            {
                if (second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }
                //> 如果枚举的和大了，就让third往前走，保证second和third并列进行
                while (third > second && nums[third] + nums[second] > target)
                    --third;
                //> 当third和second重合时，再不会有和为零的结果了
                if (third == second)
                    break;
                if (nums[second] + nums[third] == target)
                    vv.push_back({ nums[first],nums[second], nums[third] });
            }
        }
        return vv;
    }
};


