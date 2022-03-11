//> ��Ʊ���������
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int MinPro = INT_MAX;
        for (auto e : prices)
        {
            res = max(res, e - MinPro);
            MinPro = min(MinPro, e);
        }
        return res;
    }
};

//> �ַ��ǹ�
class Solution {
public:
    int candy(vector<int>& ratings) {
        //> ̰���㷨���Ⱦֲ����Ž�->ȫ�����Ž�
        //> ��ǰ����ȷ�����ڵ��Ҵ�����
        //> �Ӻ�ǰ��ȷ�����ڵ��������
        //> ���бȽϣ������ǹ���Ŀ
        int sum = 0;
        vector<int> v(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; ++i)
        {
            if (ratings[i + 1] > ratings[i])
                v[i + 1] = v[i] + 1;
        }

        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1])
                v[i] = max(v[i], v[i + 1] + 1);
        }
        for (auto e : v)
            sum += e;
        return sum;
    }
};