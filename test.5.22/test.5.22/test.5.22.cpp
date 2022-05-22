//> ����Ӯ��

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
            return false;
        //> dfs, ��ǰ״̬(�տ�ʼ���е����ֲ�δ�����)�� ��ǰ�ۼӺͣ� �����أ� Ŀ���
        //> ��ʾ��ǰ�Ƿ�һ����Ӯ
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
            //> ���� i ��ʹ�ù���
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
        //> ������������ǰ��һ���
        visited[state] = 2;
        return false;
    }
private:
    //> visited[i] = 0 : ���� i δ�����
    //> visited[i] = 1 : ���� i ������������ȡ�� i ���Ӯ
    //> visited[i] = 2 : ���� i ������������ȡ�� i �����
    int visited[1 << 21];
};

//> ��ά�����еĲ���
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

//>  �滻�ո�
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

//> ��β��ͷ��ӡ����
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
        //> ͷ�巨
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