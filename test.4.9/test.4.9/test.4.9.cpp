//>��ض�����
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
 //  0���ýڵ��޸���
 //  1�����ڵ�������ͷ
 //  2�����ڵ��и���
 // ����Ķ����丸�׽ڵ�ĵ�ǰ״̬
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        //����ģ�ͷ�ڵ�Ϊ�޸���
        if (traversal(root) == 0)
            result++;
        return result;
    }
private:
    int result;
    int traversal(TreeNode* Node)
    {
        // �սڵ㣬�и���
        if (Node == NULL)
            return 2;

        //��ȡ��������״̬
        int left = traversal(Node->left);

        int right = traversal(Node->right);

        // ���һ�����ҽڵ㶼�и���
        if (right == 2 && left == 2)
            return 0;
        // ������� ����������������һ������״̬Ϊ0���޸��ǣ�,��Ҫ���丸�ڵ㰲װ���
        // left = 0 && right = 0 ���޸������޸���
        // left = 1 && right = 0 ������ͷ���޸���
        // left = 2 && right = 0 ���и������޸���
        // left = 0 && right = 1 ���޸���������ͷ
        // left = 0 && right = 2 ���޸������޸���
        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        // ����������������ڵ㣬����һ������ͷ�����ڵ�״̬ӦΪ2
        // left = 1 && right = 2 ������ͷ���и���
        // left = 2 && right = 1 ���и���������ͷ
        // left = 1 && right = 1 ������ͷ������ͷ
        if (left == 1 || right == 1)
        {
            return 2;
        }

        return -1; // Ϊ�˷���ֵ���ó������߲�������
    }
};

//>  ʹ����С������¥��
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //> dp[i] : ��iλ������Ҫ����ͻ���
        //> dp[i]״̬ת�Ʒ��̣�dp[i] = min (dp[i-1] + cost[i-1],dp[i-2] + cost[i-2])
        //> ��ʼ����dp[0] = dp[1] = 0;
        //> �ݹ�˳�� �� -> ��
        vector<int> dp(cost.size() + 1, 0);

        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};
