class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) ǰ����� ���治����
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        while (end < sSize)
        {
            char tmpChar = s[end];
            for (int index = start; index < end; index++)
            {
                if (tmpChar == s[index])
                {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
