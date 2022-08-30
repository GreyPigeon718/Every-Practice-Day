// �����������������
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;

        for (int i = 0; i < n; ++i)
        {
            // ��ǰ�����ҵ�С�����ֵ�����һ��λ��
            if (maxn > nums[i])
            {
                right = i;
            }
            else
            {
                maxn = nums[i];
            }
            // �Ӻ�ǰ���ҵ�������Сֵ�ĵ�һ��λ��
            if (minn < nums[n - i - 1])
            {
                left = n - i - 1;
            }
            else
            {
                minn = nums[n - i - 1];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

// ��Ϊ K ��������
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // ǰ׺�ͣ�ǰ׺�ͳ��ֵĴ���
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (int& x : nums)
        {
            pre += x;
            if (mp.count(pre - x))
            {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};


// ��������ֱ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // ���������·����һ����һ������! ������·��һ��ͨ���������root�ڵ㡣"�ֱ�� = ������������������֮��"
    // �������������һһ��������������õݹ����ԣ�����ײ��������� (��������ֵΪ��ȣ��������бȽ�ÿһ��������ֱ�����Ӷ��ҵ��ֱ��)
public:
    int maxLen = 0;
    int dfs(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        maxLen = max(left + right, maxLen);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxLen;
    }
};



