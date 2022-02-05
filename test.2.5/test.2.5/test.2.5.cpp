//两句话中的不常见单词
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> res;
        stringstream a, b;  //创建流对象
        string s;
        a << s1; b << s2;   //向流中传值
        while (a >> s) mp[s]++;  //流向s中写入值，并且空格会自断开
        while (b >> s) mp[s]++;
        for (auto m : mp) if (m.second == 1)res.push_back(m.first); //只需要看出现次数是1的单词
        return res;
    }
};
