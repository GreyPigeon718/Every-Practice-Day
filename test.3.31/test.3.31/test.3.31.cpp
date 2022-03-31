//> ��������ؽ�����
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //> ������߽���������
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
            });
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); ++i)
        {
            int position = people[i][1];
            res.insert(res.begin() + position, people[i]);
        }
        return res;
    }
};

//> Excel �������
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (int i = columnTitle.size() - 1; i >= 0; --i)
        {
            res += (columnTitle[i] - 65 + 1) * pow(26, columnTitle.size() - 1 - i);
        }
        return res;
    }
};