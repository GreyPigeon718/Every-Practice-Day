class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> r(n);
        for (int i = 0; i < n; ++i) r[i] = i;//初始化rank数组
        sort(r.begin(), r.end(), [&](auto& a, auto& b) {return score[a] > score[b]; });
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) ans[r[i]] = "Gold Medal";
            else if (i == 1) ans[r[i]] = "Silver Medal";
            else if (i == 2) ans[r[i]] = "Bronze Medal";
            else ans[r[i]] = to_string(i + 1);
        }
        return ans;
    }
};