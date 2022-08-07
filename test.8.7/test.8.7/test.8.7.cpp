//> 最小时间差
class Solution {
    int getminutes(string& s)
    {
        return (int(s[0] - '0') * 10 + int(s[1] - '0')) * 60 + int(s[3] - '0') * 10 + int(s[4] - '0');
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());

        int num0 = getminutes(timePoints[0]);
        int pre = num0;
        int res = INT_MAX;
        for (int i = 1; i < timePoints.size(); ++i)
        {
            int cur = getminutes(timePoints[i]);
            res = min(res, cur - pre);
            pre = cur;
        }
        res = min(res, num0 + 1440 - pre);
        return res;
    }
};