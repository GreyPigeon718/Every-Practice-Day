//> ƽ�������
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
public:
    int getHeight(TreeNode* Node)
    {
        if (Node == NULL)
            return 0;
        int leftHeight = getHeight(Node->left);
        if (leftHeight == -1)
            return -1;
        int rightHeight = getHeight(Node->right);
        if (rightHeight == -1)
            return -1;
        return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        return getHeight(root) == -1 ? false : true;
    }
};

//> ������������·�� 
/*Definition for a binary tree node.
* struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    *TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    *
};
*/
class Solution {
public:
    void backstarck(TreeNode* Node)
    {
        path.push_back(Node->val); //> ��
        if (Node->left == NULL && Node->right == NULL)
        {
            string s;
            for (int i = 0; i < path.size() - 1; ++i)
            {
                s += to_string(path[i]);
                s += "->";
            }
            s += to_string(path[path.size() - 1]);
            res.push_back(s);
            return;
        }

        if (Node->left)
        {
            backstarck(Node->left); //> ��
            path.pop_back();
        }

        if (Node->right)
        {
            backstarck(Node->right); //> ��
            path.pop_back();
        }

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return res;
        backstarck(root);
        return res;
    }
private:
    vector<int> path;
    vector<string> res;
};

//> ��Ҷ��֮��
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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;
        int sum = 0;
        int leftTree = sumOfLeftLeaves(root->left); //> ��
        int rightTree = sumOfLeftLeaves(root->right);//> ��
        int midNode = 0;    //> ��

        if (root->left != NULL && root->left->right == NULL && root->left->left == NULL)
            midNode = root->left->val;
        sum += midNode + leftTree + rightTree;
        return sum;
    }
};

//> �������½ǵ�ֵ
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
public://> ��Ŀ����ײ㣬�������
    void GetLeftValue(TreeNode* Node, int LeftDeth)
    {
        //> �ݹ��г�������Ҷ�ӽڵ�
        if (Node->left == nullptr && Node->right == nullptr)
        {
            if (LeftDeth > maxDeth)
            {
                maxDeth = LeftDeth;
                LeftValue = Node->val;
            }
            return;
        }

        if (Node->left)  //��
        {
            LeftDeth++;
            GetLeftValue(Node->left, LeftDeth); //> ����
            LeftDeth--;
        }
        if (Node->right) //��
        {
            LeftDeth++;
            GetLeftValue(Node->right, LeftDeth); //> ����
            LeftDeth--;
        }
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        GetLeftValue(root, 0);
        return LeftValue;
    }
private:
    int maxDeth = INT_MIN;
    int LeftValue;
};

//> �ཻ����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        while (a || b)
        {
            if (a == b)
                return a;
            a = a ? a->next : headB;
            b = b ? b->next : headA;

        }
        return NULL;
    }
};

//> ·���ܺ�
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
public:
    bool flashback(TreeNode* Node, int target)
    {
        if (Node->left == nullptr && Node->right == nullptr && target == 0)
            return true;
        if (Node->left == nullptr && Node->right == nullptr)
            return false;
        if (Node->left)
        {
            target -= Node->left->val;
            if (flashback(Node->left, target))
                return true;
            target += Node->left->val;
        }
        if (Node->right)
        {
            target -= Node->right->val;
            if (flashback(Node->right, target))
                return true;
            target += Node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return flashback(root, targetSum - root->val);
    }
};


//> �Ȳ����л��� II - ������
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        // dp[3][2] = 5 -> nums[3]��β ����Ϊ2 �� �Ȳ����У����ȴ���2���ĸ���Ϊ 5
        vector<unordered_map<long long, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)nums[i] - nums[j];
                dp[i][d] += dp[j][d] + 1;
                // dp[j][d] ������ dp[i] ��ʾ�˳�������Ϊ3�ĵȲ�����
                res += dp[j][d];
            }
        }
        return res;
    }
};
