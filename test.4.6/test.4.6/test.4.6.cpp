//> ¼à¿Ø¶þ²æÊ÷
struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return { INT_MAX / 2, 0, 0 };
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return { a, b, c };
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};

