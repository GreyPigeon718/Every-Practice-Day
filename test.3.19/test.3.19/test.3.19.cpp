//> �������ľ���
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void trasurl(TreeNode* Node)
    {
        //> �ݹ��г�����ΪҶ�ӽڵ�
        if (Node->left == NULL && Node->right == NULL)
            return;
        //> �ݹ�Ľ�������
        TreeNode* tmp = Node->left;
        Node->left = Node->right;
        Node->right = tmp;
        // �ݹ�����
        if (Node->left)
            trasurl(Node->left);
        if (Node->right)
            trasurl(Node->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return root;
        trasurl(root);
        return root;
    }
};

//> �ϲ�������������
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2)
            return list1 ? list1 : list2;
        ListNode* tmp = new ListNode(-1);
        ListNode* head = tmp;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                head->next = list1;
                list1 = list1->next;
            }
            else
            {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }
        if (list1 || list2)
            head->next = list1 ? list1 : list2;
        return tmp->next;
    }
};

//> ɾ�����������е��ظ���
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // �����ǿ�������ж�
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < (nums.size() - 1); fastIndex++) {
            if (nums[fastIndex] != nums[fastIndex + 1]) { // ���ֺͺ�һ������ͬ
                nums[++slowIndex] = nums[fastIndex + 1]; //slowIndex = 0 ������һ���ǲ��ظ��ģ�����ֱ�� ++slowIndex
            }
        }
        return slowIndex + 1; //������slowIndex�Ǵ�0��ʼ�ģ����Է���slowIndex + 1
    }
};

//> �����������������й��������
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
    TreeNode* trasurl(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty())
            return NULL;

        int root = postorder[postorder.size() - 1];
        TreeNode* Node = new TreeNode(root);
        int i;
        for (i = 0; i < inorder.size(); ++i)
            if (root == inorder[i])
                break;

        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());


        Node->left = trasurl(leftInorder, leftPostorder);
        Node->right = trasurl(rightInorder, rightPostorder);

        return Node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())
            return NULL;
        return trasurl(inorder, postorder);
    }
};

//>  K ��һ�鷭ת����
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* cur = head;
        int count = 0;
        while (cur != nullptr)
        {
            count++;
            cur = cur->next;
        }
        ListNode* tmp = head;
        ListNode* tmmp;
        ListNode* res = new ListNode(0);
        head = res;

        int times = count / k;
        while (times--)
        {
            for (int i = 0; i < k; ++i)
            {
                st.push(tmp);
                tmp = tmp->next;
            }
            while (!st.empty())
            {
                tmmp = st.top();
                res->next = tmmp;
                res = res->next;
                st.pop();
            }
        }
        if (tmp != nullptr)
        {
            res->next = tmp;
        }
        else
            res->next = nullptr;
        return head->next;
    }
};