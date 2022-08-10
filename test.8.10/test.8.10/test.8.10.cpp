//> ��С�����Ӵ�
class Solution {
public:
    string minWindow(string s, string t) {
        //> ��ʾ�ַ�ȱ�ٵ�����,��128����ӳ���ַ�
        vector<int> nums(128, 0);
        //> ��ʾ�Ƿ������t�ַ���
        vector<bool> flag(128, false);

        for (int i = 0; i < t.size(); ++i)
        {
            flag[t[i]] = true;
            ++nums[t[i]];
        }

        //> �Ѱ�����������ǰ��߽磬��С�ִ�����С��߽磬��С�Ӵ��ĳ���
        int cnt = 0, l = 0, min_l = 0, min_size = s.size() + 1;
        for (int r = 0; r < s.size(); ++r)
        {
            if (flag[s[r]])
            {
                if (--nums[s[r]] >= 0)
                    cnt++;

                while (cnt == t.size())
                {
                    if (r - l + 1 < min_size)
                    {
                        min_l = l;
                        min_size = r - l + 1;
                    }

                    if (flag[s[l]] && ++nums[s[l]] > 0)
                        cnt--;

                    ++l;
                }
            }

        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};