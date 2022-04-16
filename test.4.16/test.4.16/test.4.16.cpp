class Solution {
public:
    bool traversal(const string& s, const unordered_set<string>& ut, vector<bool>& memory, int startIndex)
    {
        //> 回溯判出条件：startIndex >= s.size()
        if (startIndex >= s.size())
            return true;
        for (int i = startIndex; i < s.size(); ++i)
        {
            string word = s.substr(startIndex, i - startIndex + 1);
            if (ut.count(word) == 1 && traversal(s, ut, memory, i + 1))
                return true;
        }
        memory[startIndex] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ut(wordDict.begin(), wordDict.end());
        vector<bool> memory(s.size() + 1, true);
        return traversal(s, ut, memory, 0);
    }
};
