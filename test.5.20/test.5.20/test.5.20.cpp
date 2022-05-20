#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
	unordered_set<int> ust;
	ust.insert(1);
	cout << *ust.begin();
}

//> 寻找右区间
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
            //> lower_bound: 返回
            map<int, int> ::iterator  it = ump.lower_bound(intervals[i][1]);
            if (it != ump.end())
                res.emplace_back(it->second);
            else
                res.emplace_back(-1);
        }
        return res;
    }
};


//> 二叉树中的最大路径和

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
    //> 情况可分为两类：A类节点和B类节点
    //>                A
    //>             /     \  
    //>            B       B
    //>                     \
    //>                      B
    //> A类节点可以将左右连接起来 left+right+root->val
    //> B类节点只能断开取一边 max(left, right)
    int maxpath(TreeNode* root)
    {
        //> 递归判出条件
        if (root == nullptr)
            return 0;
        //> 左子树的路径最大值
        int left = max(0, maxpath(root->left));
        //> 右子树的路径最大值
        int right = max(0, maxpath(root->right));

        //A类节点
        res = max(res, root->val + left + right);
        //B类节点
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