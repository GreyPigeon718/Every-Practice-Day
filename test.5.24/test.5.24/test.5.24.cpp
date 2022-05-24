//> 单词搜索
class Solution {
public:
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool exist(vector<vector<char>>& board, string word) {
        //> 回溯
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                //> 参数：网格，字符串单词，单词的第几位字符， xy坐标
                if (dfs(board, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int index, int x, int y)
    {
        if (board[x][y] != word[index])
            return false;
        if (index == word.size() - 1)
            return true;
        //> 标记前保存字符
        char tmp = board[x][y];
        //> 标记代表遍历过
        board[x][y] = '.';
        for (int i = 0; i < 4; ++i)
        {
            int a = dx[i] + x;
            int b = dy[i] + y;
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.')
                continue;
            if (dfs(board, word, index + 1, a, b))
                return true;
        }
        board[x][y] = tmp;
        return false;
    }
};

//> 重建二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < preorder.size(); ++i)
        {
            ump[inorder[i]] = i;
        }
        //> 先序， 中序， 先序头节点， 中序左边界， 中序右边界
        return recvTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* recvTree(const vector<int>& preorder, const vector<int>& inorder,
        int pre_root, int in_left, int in_right)
    {
        //> 递归判出条件
        if (in_left > in_right)
            return NULL;
        //> 根节点
        TreeNode* root = new TreeNode(preorder[pre_root]);
        //> 根节点在中序序列中的位置，用于划分左右子树的边界
        int in_root = ump[preorder[pre_root]];
        //> 左子树在先序中的根节点： pre_root+1, 中序序列当前边界： [当前左边界， 根节点的位置-1]
        root->left = recvTree(preorder, inorder, pre_root + 1, in_left, in_root - 1);
        //> 右子树在先序中的根节点：pre_root + in_root - in_left + 1
        //> 中序序列当前边界： [根节点的位置+1, 当前右边界]
        root->right = recvTree(preorder, inorder, pre_root + in_root - in_left + 1, in_root + 1, in_right);

        return root;
    }
private:
    unordered_map<int, int> ump;
};

