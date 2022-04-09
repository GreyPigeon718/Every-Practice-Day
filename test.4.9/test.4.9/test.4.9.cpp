//>监控二叉树
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
 //  0：该节点无覆盖
 //  1：本节点有摄像头
 //  2：本节点有覆盖
 // 输出的都是其父亲节点的当前状态
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        //情况四，头节点为无覆盖
        if (traversal(root) == 0)
            result++;
        return result;
    }
private:
    int result;
    int traversal(TreeNode* Node)
    {
        // 空节点，有覆盖
        if (Node == NULL)
            return 2;

        //获取左右子树状态
        int left = traversal(Node->left);

        int right = traversal(Node->right);

        // 情况一，左右节点都有覆盖
        if (right == 2 && left == 2)
            return 0;
        // 情况二， 左右子树，有任意一个子树状态为0（无覆盖）,就要在其父节点安装监控
        // left = 0 && right = 0 左无覆盖右无覆盖
        // left = 1 && right = 0 左摄像头右无覆盖
        // left = 2 && right = 0 左有覆盖右无覆盖
        // left = 0 && right = 1 左无覆盖右摄像头
        // left = 0 && right = 2 左无覆盖右无覆盖
        if (left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        // 情况三、左右子树节点，至少一个摄像头，父节点状态应为2
        // left = 1 && right = 2 左摄像头右有覆盖
        // left = 2 && right = 1 左有覆盖右摄像头
        // left = 1 && right = 1 左摄像头右摄像头
        if (left == 1 || right == 1)
        {
            return 2;
        }

        return -1; // 为了返回值，该程序是走不到这里
    }
};

//>  使用最小花费爬楼梯
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //> dp[i] : 到i位置所需要的最低花费
        //> dp[i]状态转移方程：dp[i] = min (dp[i-1] + cost[i-1],dp[i-2] + cost[i-2])
        //> 初始化：dp[0] = dp[1] = 0;
        //> 递归顺序 左 -> 右
        vector<int> dp(cost.size() + 1, 0);

        for (int i = 2; i <= cost.size(); ++i)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[cost.size()];
    }
};
