//Á¬Ðø×Ö·û
class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int Maxlength = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                Maxlength++;
                res = max(Maxlength, res);
            }
            else
                Maxlength = 1;
        }
        return res;
    }
};