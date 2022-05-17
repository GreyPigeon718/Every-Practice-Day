//> ��֤������ʵ�
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> ump;

        //> ��order����ַ����±�һһ��Ӧ����
        for (int i = 0; i < order.size(); ++i)
        {
            ump[order[i]] = i;
        }

        vector<string> v;
        //> ��words���wordӳ�䵽order��ĸ����
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