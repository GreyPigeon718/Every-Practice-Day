//> 验证外星语词典
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ump;

        //> 把order里的字符和下标一一对应起来
        for (int i = 0; i < order.size(); ++i)
        {
            ump[order[i]] = i;
        }

        vector<string> v;
        //> 把words里的word映射到order字母表中
        for (string& word : words)
        {
            string tmp;
            for (char c : word)
            {
                tmp += 'a' + ump[c];
            }
            v.emplace_back(tmp);
        }
        return is_sorted(v.begin(), v.end());
    }
};