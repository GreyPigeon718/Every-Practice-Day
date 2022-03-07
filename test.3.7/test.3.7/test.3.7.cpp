//> Æß½øÖÆÊı
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
        int flag = 1;
        string s = "";
        if (num < 0)
        {
            flag = -1;
            num = -num;
        }
        while (num >= 7)
        {
            int a = num % 7;
            s = to_string(a) + s;
            num /= 7;
        }
        s = to_string(num) + s;
        if (flag == -1)
            return "-" + s;
        return s;
    }
};