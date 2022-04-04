//> 划分字母区间
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> up;
        for (int i = 0; i < s.size(); ++i)
            up[s[i]] = i;
        vector<int> result;
        int right = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            right = max(right, up[s[i]]); //> 字符出现的最右边界
            if (i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return result;
    }
};

//> 合并区间
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //> 局部最优解：最右边界为最大的
        //> 全局最优解：合并最大的重叠区间
        sort(intervals.begin(), intervals.end(), cmp);
        bool flag = false;
        vector<vector<int>> result;

        for (int i = 1; i < intervals.size(); ++i)
        {
            int start = intervals[i - 1][0];
            int end = intervals[i - 1][1];
            while (i < intervals.size() && intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
                if (i == intervals.size() - 1) //> 表示最有一个也合并了
                    flag = true;
                ++i;
            }
            result.push_back({ start, end });
        }
        if (flag == false) {
            result.push_back({ intervals[intervals.size() - 1][0], intervals[intervals.size() - 1][1] });
        }
        return result;
    }
};


//> 单调递增的数字

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string strNum = to_string(N);
        // flag用来标记赋值9从哪里开始
        // 设置为这个默认值，为了防止第二个for循环在flag没有被赋值的情况下执行
        int flag = strNum.size();
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i - 1] > strNum[i]) {
                flag = i;
                strNum[i - 1]--;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
