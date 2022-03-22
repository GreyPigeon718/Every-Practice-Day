//> �����������еĲ������
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
    //> ����Ҫ����ȫ������������Ҫ����ֵ
    TreeNode* traversal(TreeNode* Node, int val)
    {
        //> �ݹ��г�������NodeΪ��
        if (Node == NULL)
        {
            TreeNode* head = new TreeNode(val);
            return head;
        }
        //> ����ݹ飬���ݶ����������������ԣ����ݲ���Ԫ�����жϵݹ�˳��
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


//> ˳ʱ���ӡ����
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty())
            return v;
        //> ˳ʱ�� ��->��->��->��
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


//> ���������ƽ��
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //> ˫ָ��
        //> ��˼·���������飬����ƽ����ǰһ�������ִӵ�����ɵݼ�
        //> һ��ָ��ָ����ߣ�һ��ָ��ָ���ұ�
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

//>  �ϲ�������������
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


//> ��С�����Ӵ�
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
            //> �������ڣ�����t�ַ�
            if (need.count(s[right]))
            {
                windows[s[right]]++;
                //> ��¼ t�ַ����ֵĴ���
                if (windows[s[right]] == need[s[right]])
                    count++;
            }
            //> ��������ڸ�����ɣ���ʼ������ߴ���
            while (count == need.size())
            {
                //> �ַ�����ȡ
                if (min_len > right - left + 1)
                {
                    res = s.substr(left, right - left + 1);
                    min_len = right - left + 1;
                }
                //> ������ǡ�ò����ǣ�Ҳ����count = need.size() - 1
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


//> ɾ�������������еĽڵ�
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
    //> ɾ���ڵ�ͳһ�ǽ�ɾ���ڵ��������ƴ�ӵ�ɾ���ڵ��������������ڵ�
    //> ��������½ڵ�
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
        //> �ҵ��ڵ�λ��
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


//> �޼�����������
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
        //> �г�����
        if (Node == nullptr)
            return nullptr;
        //> �ݹ��߼�����lowС�����ҵݹ飬��high������ݹ�
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

        //> ���ҵ�right��left�ڵ㸳��Node
        Node->left = traversal(Node->left, low, high);
        Node->right = traversal(Node->right, low, high);

        //> ����Node
        return Node;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return traversal(root, low, high);
    }
};

//> ����������ת��Ϊ����������
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
        //>�г�����
        if (left > right)
            return nullptr;
        int mid = (right - left) / 2 + left;
        TreeNode* root = new TreeNode(nums[mid]);
        //> �������飬�߶�ƽ����ڶ�����������Ȼ��ݹ���һ�㣬�����ƽ�������
        root->left = tarversal(nums, left, mid - 1);
        root->right = tarversal(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //>��֪����������
        return tarversal(nums, 0, nums.size() - 1);
    }
};

//>  �Ѷ���������ת��Ϊ�ۼ���
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
        //> �ݹ��г�����
        if (Node == nullptr)
            return;
        //> ����ݹ飬ÿһ��ݹ鱣���ۼӸýڵ��ֵ
        traversal(Node->right);
        sum += Node->val;
        Node->val = sum;
        traversal(Node->left);

    }
    TreeNode* convertBST(TreeNode* root) {
        //> �ۼ��� ������˳�� �� �Ҹ���
        if (root == nullptr)
            return nullptr;
        traversal(root);
        return root;
    }
};


//> �Ӷ������������������
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
        //> �ݹ��г�����
        if (Node == nullptr)
            return;
        //> ����ݹ飬ÿһ��ݹ鱣���ۼӸýڵ��ֵ
        traversal(Node->right);
        sum += Node->val;
        Node->val = sum;
        traversal(Node->left);

    }
    TreeNode* bstToGst(TreeNode* root) {
        //> �ۼ��� ������˳�� �� �Ҹ���
        if (root == nullptr)
            return nullptr;
        traversal(root);
        return root;
    }
};