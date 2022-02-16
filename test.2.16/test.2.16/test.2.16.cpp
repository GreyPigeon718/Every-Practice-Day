//> 比较含退格的字符串
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        //> 将字符放入栈中，会有三种情况
        //> 1.栈不为空，字符为‘#’
        //> 2.栈为空，字符为‘#’
        //> 3.字符正常插入
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '#' && !st1.empty())
                st1.pop();
            else if (s[i] == '#' && st1.empty())
                continue;
            else
                st1.push(s[i]);
        }
        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] == '#' && !st2.empty())
                st2.pop();
            else if (t[i] == '#' && st2.empty())
                continue;
            else
                st2.push(t[i]);
        }
        //> 栈比较，都为空说明都一样，如不是空，循环先退出，则不为空
        while (!st1.empty() && !st2.empty() && st1.top() == st2.top())
        {
            st1.pop();
            st2.pop();
        }
        if (st1.empty() && st2.empty())
            return true;
        return false;
    }
};

//> 区间列表的交集
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> vv;
        if (firstList.empty() || secondList.empty())
            return vv;
        int i = 0, j = 0;
        //> 两个列表同时进行遍历
        while (i < firstList.size() && j < secondList.size())
        {
            //> 第一列表区间的右边界 < 第二列表区间的左边界，那么第一区间向后移动
            if (firstList[i][1] < secondList[j][0])
                i++;
            //> 第一列表区间的左边界 > 第二列表区间的右边界，那么第二区间向后移动
            else if (firstList[i][0] > secondList[j][1])
                j++;
            //> 这个时候就有交集了
            else
            {
                int left = max(firstList[i][0], secondList[j][0]);
                int right = min(firstList[i][1], secondList[j][1]);
                vv.push_back({ left,right });
                //> 第一列表区间的右边界 < 第二列表区间的右边界，第一区间向后移动
                if (firstList[i][1] < secondList[j][1])
                    i++;
                //> 第一列表区间的右边界 > 第二列表区间的右边界，第二区间向后移动
                else
                    j++;
            }
        }
        return vv;
    }
};

//>  盛最多水的容器
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0, end = height.size() - 1;
        int res = -1;
        while (begin < end)
        {
            //> 算出当前容器所盛的水
            res = max(res, (end - begin) * min(height[begin], height[end]));
            //> 如果左指针小，那么左指针向后移动。
            if (height[begin] < height[end])
                begin++;
            //> 如果右指针小，那么右指针向后移动。
            //> 两个指针相等的话，移动任意一个指针，这里移动右指针
            else
                end--;
        }
        return res;
    }
};