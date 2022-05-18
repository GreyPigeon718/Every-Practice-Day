//#include <iostream>
//using namespace std; 
//void fun(int a, int b = 1,int c = 8) { cout << a + b + c << endl; } 
//int main(void) 
//{ fun(1,3); return 0; }


#include <iostream>
using namespace std;
class S { public: ~S() { cout << "S "; } }; 
char fun() { S s1; throw('A'); return 'O'; } 
int main() { try { cout << fun(); }catch (char c) { cout << c; } } 

//> 环形链表II
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*> ust;

        while (head)
        {
            if (ust.count(head))
            {
                return head;
            }
            ust.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

//> 排序链表
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> res;
        if (head == nullptr)
            return head;
        while (head)
        {
            res.emplace_back(head->val);
            head = head->next;
        }
        sort(res.begin(), res.end());
        ListNode* tmp;
        for (int num : res)
        {
            ListNode* Node = new ListNode(num);
            if (head == nullptr)
            {
                head = Node;
                tmp = Node;
            }
            else
            {
                head->next = Node;
                head = head->next;
            }
        }
        return tmp;
    }
};

//> 二叉搜索树中第K小的元素
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sk;
        int res;
        while (!sk.empty() || root)
        {
            while (root)
            {
                sk.push(root);
                root = root->left;
            }

            root = sk.top();
            sk.pop();

            --k;
            if (k == 0)
            {
                break;
            }

            root = root->right;
        }
        return root->val;
    }
};