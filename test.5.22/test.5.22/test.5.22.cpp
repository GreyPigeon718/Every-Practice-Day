//> 我能赢吗

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
            return false;
        //> dfs, 当前状态(刚开始所有的数字并未计算过)， 当前累加和， 整数池， 目标和
        //> 表示当前是否一定会赢
        return dfs(0, 0, maxChoosableInteger, desiredTotal);
    }

    bool dfs(int state, int sum, int maxChoosableInteger, int desiredTotal)
    {
        if (visited[state] == 1)
            return true;
        if (visited[state] == 2)
            return false;

        for (int i = 1; i <= maxChoosableInteger; ++i)
        {
            //> 数字 i 被使用过了
            if ((1 << i) & state)
                continue;
            if (sum + i >= desiredTotal)
            {
                visited[state] = 1;
                return true;
            }
            if (!dfs((1 << i) | state, sum + i, maxChoosableInteger, desiredTotal))
            {
                visited[state] = 1;
                return true;
            }
        }
        //> 参与计算过，当前玩家会输
        visited[state] = 2;
        return false;
    }
private:
    //> visited[i] = 0 : 数字 i 未计算过
    //> visited[i] = 1 : 数字 i 计算过，该玩家取到 i 后必赢
    //> visited[i] = 2 : 数字 i 计算过，该玩家取到 i 后必输
    int visited[1 << 21];
};

//> 二维数组中的查找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
};

//>  替换空格
class Solution {
public:
    string replaceSpace(string s) {
        string _s = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                _s += "%20";
            }
            else
                _s += s[i];
        }
        return _s;
    }
};

//> 从尾到头打印链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        //> 头插法
        vector<int> res;
        while (head)
        {
            res.emplace_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};