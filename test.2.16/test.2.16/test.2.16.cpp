//> �ȽϺ��˸���ַ���
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        //> ���ַ�����ջ�У������������
        //> 1.ջ��Ϊ�գ��ַ�Ϊ��#��
        //> 2.ջΪ�գ��ַ�Ϊ��#��
        //> 3.�ַ���������
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
        //> ջ�Ƚϣ���Ϊ��˵����һ�����粻�ǿգ�ѭ�����˳�����Ϊ��
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

//> �����б�Ľ���
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> vv;
        if (firstList.empty() || secondList.empty())
            return vv;
        int i = 0, j = 0;
        //> �����б�ͬʱ���б���
        while (i < firstList.size() && j < secondList.size())
        {
            //> ��һ�б�������ұ߽� < �ڶ��б��������߽磬��ô��һ��������ƶ�
            if (firstList[i][1] < secondList[j][0])
                i++;
            //> ��һ�б��������߽� > �ڶ��б�������ұ߽磬��ô�ڶ���������ƶ�
            else if (firstList[i][0] > secondList[j][1])
                j++;
            //> ���ʱ����н�����
            else
            {
                int left = max(firstList[i][0], secondList[j][0]);
                int right = min(firstList[i][1], secondList[j][1]);
                vv.push_back({ left,right });
                //> ��һ�б�������ұ߽� < �ڶ��б�������ұ߽磬��һ��������ƶ�
                if (firstList[i][1] < secondList[j][1])
                    i++;
                //> ��һ�б�������ұ߽� > �ڶ��б�������ұ߽磬�ڶ���������ƶ�
                else
                    j++;
            }
        }
        return vv;
    }
};

//>  ʢ���ˮ������
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin = 0, end = height.size() - 1;
        int res = -1;
        while (begin < end)
        {
            //> �����ǰ������ʢ��ˮ
            res = max(res, (end - begin) * min(height[begin], height[end]));
            //> �����ָ��С����ô��ָ������ƶ���
            if (height[begin] < height[end])
                begin++;
            //> �����ָ��С����ô��ָ������ƶ���
            //> ����ָ����ȵĻ����ƶ�����һ��ָ�룬�����ƶ���ָ��
            else
                end--;
        }
        return res;
    }
};