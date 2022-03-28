//> 买卖股票的最佳时机 II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> v(prices.size(), 0);
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            v[i] = prices[i] - prices[i - 1];
        }
        for (int price : v)
        {
            if (price > 0)
                res += price;
        }
        return res;
    }
};


//> N 叉树的最大深度
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int maxChildDepth = 0;
        vector<Node*> children = root->children;
        for (Node* child : children) {
            int childDepth = maxDepth(child);
            maxChildDepth = max(maxChildDepth, childDepth);
        }
        return maxChildDepth + 1;
    }
};

