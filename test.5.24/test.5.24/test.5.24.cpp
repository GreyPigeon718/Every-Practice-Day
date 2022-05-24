//> ��������
class Solution {
public:
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool exist(vector<vector<char>>& board, string word) {
        //> ����
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                //> �����������ַ������ʣ����ʵĵڼ�λ�ַ��� xy����
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
        //> ���ǰ�����ַ�
        char tmp = board[x][y];
        //> ��Ǵ��������
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

//> �ؽ�������
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
        //> ���� ���� ����ͷ�ڵ㣬 ������߽磬 �����ұ߽�
        return recvTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
    TreeNode* recvTree(const vector<int>& preorder, const vector<int>& inorder,
        int pre_root, int in_left, int in_right)
    {
        //> �ݹ��г�����
        if (in_left > in_right)
            return NULL;
        //> ���ڵ�
        TreeNode* root = new TreeNode(preorder[pre_root]);
        //> ���ڵ������������е�λ�ã����ڻ������������ı߽�
        int in_root = ump[preorder[pre_root]];
        //> �������������еĸ��ڵ㣺 pre_root+1, �������е�ǰ�߽磺 [��ǰ��߽磬 ���ڵ��λ��-1]
        root->left = recvTree(preorder, inorder, pre_root + 1, in_left, in_root - 1);
        //> �������������еĸ��ڵ㣺pre_root + in_root - in_left + 1
        //> �������е�ǰ�߽磺 [���ڵ��λ��+1, ��ǰ�ұ߽�]
        root->right = recvTree(preorder, inorder, pre_root + in_root - in_left + 1, in_root + 1, in_right);

        return root;
    }
private:
    unordered_map<int, int> ump;
};

