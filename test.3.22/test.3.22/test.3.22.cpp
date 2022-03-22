//> 二叉搜索树中的插入操作
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
    //> 不需要遍历全部树，所有需要返回值
    TreeNode* traversal(TreeNode* Node, int val)
    {
        //> 递归判出条件：Node为空
        if (Node == NULL)
        {
            TreeNode* head = new TreeNode(val);
            return head;
        }
        //> 单层递归，根据二叉搜索树的有序性，根据插入元素啦判断递归顺序
        if (Node->val > val)
            Node->left = traversal(Node->left, val);
        else
            Node->right = traversal(Node->right, val);
        return Node;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return traversal(root, val);
    }
};


//> 顺时针打印矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty())
            return v;
        //> 顺时针 左->下->右->上
        int left = 0, right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1, top = 0;
        while (left <= right && top <= bottom)
        {
            //> (top,left)->(top,right)
            for (int i = left; i <= right; ++i)
                v.emplace_back(matrix[top][i]);

            //> (top,right)->(bottom,right)
            for (int i = top + 1; i <= bottom; ++i)
                v.emplace_back(matrix[i][right]);

            if (left < right&& top < bottom)
            {
                //> (bottom,right)->(bottom,left)
                for (int i = right - 1; i > left; --i)
                    v.emplace_back(matrix[bottom][i]);

                //> (bottom,left)->(top,left)
                for (int i = bottom; i > top; --i)
                    v.emplace_back(matrix[i][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return v;
    }
};


//> 有序数组的平方
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //> 双指针
        //> 简单思路：有序数组，负数平方后，前一负数部分从递增变成递减
        //> 一个指针指向左边，一个指针指向右边
        int left = 0, right = nums.size() - 1;
        int k = right;
        vector<int> v(nums.size());
        while (left <= right)
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                v[k--] = nums[right] * nums[right];
                right--;
            }
            else
            {
                v[k--] = nums[left] * nums[left];
                left++;
            }
        }
        return v;
    }
};

//>  合并两个有序数组
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            }
            else if (p2 == n) {
                cur = nums1[p1++];
            }
            else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            }
            else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};


//> 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        int left = 0, right = 0;
        string res = "";
        int count = 0;
        int min_len = INT_MAX;
        unordered_map<char, int> need;
        unordered_map<char, int> windows;
        for (int i = 0; i < t.size(); ++i)
            need[t[i]]++;
        while (right < s.size())
        {
            //> 滑动窗口，出现t字符
            if (need.count(s[right]))
            {
                windows[s[right]]++;
                //> 记录 t字符出现的次数
                if (windows[s[right]] == need[s[right]])
                    count++;
            }
            //> 当这个窗口覆盖完成，开始收缩左边窗口
            while (count == need.size())
            {
                //> 字符串截取
                if (min_len > right - left + 1)
                {
                    res = s.substr(left, right - left + 1);
                    min_len = right - left + 1;
                }
                //> 收缩到恰好不覆盖，也就是count = need.size() - 1
                if (need.count(s[left]))
                {
                    if (windows[s[left]] == need[s[left]])
                        count--;
                    windows[s[left]]--;
                }
                left++;
            }
            right++;
        }
        return res;
    }
};


//> 删除二叉搜索树中的节点
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
    //> 删除节点统一是将删除节点的左子树拼接到删除节点的右子树的最左节点
    //> 返回这个新节点
    TreeNode* deleteOneNode(TreeNode* Node)
    {
        if (Node == nullptr)
            return Node;
        if (Node->right == nullptr)
            return Node->left;
        TreeNode* cur = Node->right;
        while (cur->left)
            cur = cur->left;
        cur->left = Node->left;
        return Node->right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //> 找到节点位置
        if (root == nullptr)
            return root;
        TreeNode* cur = root;
        TreeNode* parent = nullptr;
        while (cur && cur->val != key)
        {
            parent = cur;
            if (cur->val > key)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (parent == nullptr)
            return deleteOneNode(cur);

        if (parent->left && parent->left == cur)
            parent->left = deleteOneNode(cur);
        if (parent->right && parent->right == cur)
            parent->right = deleteOneNode(cur);
        return root;
    }
};


//> 修剪二叉搜索树
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
    TreeNode* traversal(TreeNode* Node, int low, int high)
    {
        //> 判出条件
        if (Node == nullptr)
            return nullptr;
        //> 递归逻辑，比low小，向右递归，比high大，向左递归
        if (Node->val < low)
        {
            TreeNode* right = traversal(Node->right, low, high);
            return right;
        }
        if (Node->val > high)
        {
            TreeNode* left = traversal(Node->left, low, high);
            return left;
        }

        //> 将找到right和left节点赋给Node
        Node->left = traversal(Node->left, low, high);
        Node->right = traversal(Node->right, low, high);

        //> 返回Node
        return Node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traversal(root, low, high);
    }
};

//> 将有序数组转换为二叉搜索树
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
    TreeNode* tarversal(vector<int>& nums, int left, int right)
    {
        //>判出条件
        if (left > right)
            return nullptr;
        int mid = (right - left) / 2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        //> 升序数组，高度平衡基于二叉搜索树，然后递归下一层，来达成平衡二叉树
        root->left = tarversal(nums, left, mid - 1);
        root->right = tarversal(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //>已知数组是升序
        return tarversal(nums, 0, nums.size() - 1);
    }
};

//>  把二叉搜索树转换为累加树
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
    int sum = 0;
    void traversal(TreeNode* Node)
    {
        //> 递归判出条件
        if (Node == nullptr)
            return;
        //> 单层递归，每一层递归保留累加该节点的值
        traversal(Node->right);
        sum += Node->val;
        Node->val = sum;
        traversal(Node->left);

    }
    TreeNode* convertBST(TreeNode* root) {
        //> 累加树 遍历的顺序 是 右根左
        if (root == nullptr)
            return nullptr;
        traversal(root);
        return root;
    }
};


//> 从二叉搜索树到更大和树
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
    int sum = 0;
    void traversal(TreeNode* Node)
    {
        //> 递归判出条件
        if (Node == nullptr)
            return;
        //> 单层递归，每一层递归保留累加该节点的值
        traversal(Node->right);
        sum += Node->val;
        Node->val = sum;
        traversal(Node->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        //> 累加树 遍历的顺序 是 右根左
        if (root == nullptr)
            return nullptr;
        traversal(root);
        return root;
    }
};