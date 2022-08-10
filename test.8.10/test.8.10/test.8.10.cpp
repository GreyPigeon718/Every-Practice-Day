//> 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        //> 表示字符缺少的数量,用128数组映射字符
        vector<int> nums(128, 0);
        //> 表示是否包含在t字符串
        vector<bool> flag(128, false);

        for (int i = 0; i < t.size(); ++i)
        {
            flag[t[i]] = true;
            ++nums[t[i]];
        }

        //> 已包含个数，当前左边界，最小字串的最小左边界，最小子串的长度
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