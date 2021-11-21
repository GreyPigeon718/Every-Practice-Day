//�ؽ�������
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* RulerTree(vector<int> pre, int left1, int right1, vector<int> vin, int left2, int right2)
    {
        //  ���ٵ�ǰ���ڵ�ռ�
        TreeNode* root = new TreeNode(pre[left1]);
        int x = left2;
        //. �ҵ���ǰ���ڵ������������λ��
        while (pre[left1] != vin[x])
            x++;
        int left = x - left2;//������
        int right = right2 - x; //������
        if (left > 0)
            root->left = RulerTree(pre, left1 + 1, left1 + left, vin, left2, x - 1);
        if (right > 0)
            root->right = RulerTree(pre, left1 + left + 1, right1, vin, x + 1, right2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty())
            return nullptr;
        return RulerTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    }
};
//�����������ĵ�k���ڵ�
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param proot TreeNode��
     * @param k int����
     * @return int����
     */
    void preorder(vector<int>& v, TreeNode* proot)
    {
        if (proot == nullptr)
            return;
        v.push_back(proot->val);
        preorder(v, proot->left);
        preorder(v, proot->right);
    }
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (proot == nullptr)
            return -1;
        vector<int> v;
        preorder(v, proot);
        if (k < 1 || k > v.size())
            return -1;
        sort(v.begin(), v.end());
        return v[k - 1];
    }
};// ����֮���δ�ӡ������
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (pRoot == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<vector<int>> vv;
        int count = -1; //�����һ�μ�Ϊż��
        while (!q.empty())
        {
            count++;
            int size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode* Node = q.front();
                q.pop();
                v.push_back(Node->val);
                //�������
                if (Node->left)
                    q.push(Node->left);
                if (Node->right)
                    q.push(Node->right);
            }
            if (count % 2)
                reverse(v.begin(), v.end());
            vv.push_back(v);
        }
        return vv;
    }
};
// ����ظ����ִ�
class Solution {
public:
    /**
     *
     * @param arr int����vector the array
     * @return int����
     */
    int maxLength(vector<int>& arr) {
        // write code here
        unordered_map<int, int > mp;
        int left = 0;
        int right = 0;
        int ret = 1;
        while (right < arr.size())
        {
            //   ������չmap
            if (mp[arr[right]] == 0)
            {
                mp[arr[right]] = right + 1;
                ret = max(ret, right - left + 1);
            }
            //   ��������map
            else
            {
                while (left < mp[arr[right]])
                {
                    mp[arr[left]] = 0;
                    left++;
                }
                mp[arr[right]] = right + 1;
            }
            right++;
        }
        return ret;
    }
};
//�ڶ��������ҵ������ڵ�������������
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     *
     * @param root TreeNode��
     * @param o1 int����
     * @param o2 int����
     * @return int����
     */
    TreeNode* DFS(TreeNode* Node, int o1, int o2)
    {
        if (Node == nullptr)
            return nullptr;
        if (Node->val == o1 || Node->val == o2)
            return Node;
        TreeNode* left = DFS(Node->left, o1, o2);
        TreeNode* right = DFS(Node->right, o1, o2);
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return Node;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        //TreeNode* grandNode = DFS(root, o1, o2);
        return DFS(root, o1, o2)->val;
    }
};
// ���ֲ���II
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
     * @param nums int����vector
     * @param target int����
     * @return int����
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
                right--;
            else if (nums[mid] < target)
                left++;
            else
            {
                while (mid != 0 && nums[mid] == nums[mid - 1])
                    mid--;
                return mid;
            }
        }
        return -1;
    }
};