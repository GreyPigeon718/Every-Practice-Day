//���仰�еĲ���������
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        vector<string> res;
        stringstream a, b;  //����������
        string s;
        a << s1; b << s2;   //�����д�ֵ
        while (a >> s) mp[s]++;  //����s��д��ֵ�����ҿո���ԶϿ�
        while (b >> s) mp[s]++;
        for (auto m : mp) if (m.second == 1)res.push_back(m.first); //ֻ��Ҫ�����ִ�����1�ĵ���
        return res;
    }
};
