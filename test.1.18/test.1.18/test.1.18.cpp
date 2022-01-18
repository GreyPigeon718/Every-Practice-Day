// �ַ���������
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used) {
        // ��ʱ˵���ҵ���һ��
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // used[i - 1] == true��˵��ͬһ��֧nums[i - 1]ʹ�ù�
            // used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
            // ���ͬһ����nums[i - 1]ʹ�ù���ֱ������
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // ����
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

class Solution {
public:
    string path;
    vector<string> res;
    bool used[20];

    void dfs(string s, int x) {
        if (x == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            if (i > 0 && s[i] == s[i - 1] && used[i - 1] == false) continue;
            if (!used[i]) {
                path += s[i];
                used[i] = true;
                dfs(s, x + 1);
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        res.clear();
        path.clear();
        sort(s.begin(), s.end());
        dfs(s, 0);
        return res;
    }
};