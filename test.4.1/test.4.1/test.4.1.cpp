//> ������������
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        //> ��������
        sort(arr.begin(), arr.end());
        unordered_map<int, int> up;

        for (int e : arr)
        {
            //> >0
            if (e % 2 == 0 && e > 0 && up[e / 2])
                up[e / 2]--;
            //>  <0
            else if (e < 0 && up[2 * e])
                up[2 * e]--;
            else
                up[e]++;
        }
        for (auto num : up)
        {
            if (num.first == 0)
            {
                if (num.second % 2 == 0)
                    continue;
                return false;
            }
            if (num.second)
                return false;
        }
        return true;
    }
};

//> �����������ļ���������
class Solution {
private:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), cmp);

        int result = 1; // points ��Ϊ��������Ҫһ֧��
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {  // ����i������i-1�����ţ�ע�����ﲻ��>=
                result++; // ��Ҫһ֧��
            }
            else {  // ����i������i-1����
                points[i][1] = min(points[i - 1][1], points[i][1]); // �����ص�������С�ұ߽�
            }
        }
        return result;
    }
};
