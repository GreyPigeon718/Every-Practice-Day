#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<int> ust;
	ust.insert(1);
	cout << *ust.begin();
}

//> Ѱ��������
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> ump;
        vector<int> res;
        int size = intervals.size();
        for (int i = 0; i < size; ++i)
        {
            ump[intervals[i][0]] = i;
        }

        for (int i = 0; i < size; ++i)
        {
            //> lower_bound: ����
            map<int, int> ::iterator  it = ump.lower_bound(intervals[i][1]);
            if (it != ump.end())
                res.emplace_back(it->second);
            else
                res.emplace_back(-1);
        }
        return res;
    }
};


//> �������е����·����

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
    //> ����ɷ�Ϊ���ࣺA��ڵ��B��ڵ�
    //>                A
    //>             /     \  
    //>            B       B
    //>                     \
    //>                      B
    //> A��ڵ���Խ������������� left+right+root->val
    //> B��ڵ�ֻ�ܶϿ�ȡһ�� max(left, right)
    int maxpath(TreeNode* root)
    {
        //> �ݹ��г�����
        if (root == nullptr)
            return 0;
        //> ��������·�����ֵ
        int left = max(0, maxpath(root->left));
        //> ��������·�����ֵ
        int right = max(0, maxpath(root->right));

        //A��ڵ�
        res = max(res, root->val + left + right);
        //B��ڵ�
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        maxpath(root);
        return res;
    }
private:
    int res;
};