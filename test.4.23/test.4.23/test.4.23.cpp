//> �ַ������
class Solution {
public:
    string addStrings(string& num1, string& num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans;
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            int result = x + y + add;
            ans.push_back(result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans) {
            c += '0';
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        //> �����һ��Ϊ��
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--) // �Եڶ�����Ϊ�ֿ����ֵĸ���
        {
            string cur;
            int add = 0; // ��λ��ֵ
            for (int j = n - 1; j > i; --j) // �������Ϊ������Ҫ����
            {
                cur.push_back(0);
            }
            int y = num2[i] - '0';   // 23    456
            for (int j = m - 1; j >= 0; --j)  // ���ÿһ��������������
            {
                int x = num1[j] - '0';
                int product = x * y + add;
                cur.push_back(product % 10);
                add = product / 10;
            }
            if (add != 0)
            {
                cur.push_back(add % 10);
                add /= 10;
            }
            reverse(cur.begin(), cur.end());
            for (auto& c : cur)
            {
                c += '0';
            }
            ans = addStrings(ans, cur);
        }
        return ans;
    }
};
//> �ַ������
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        int carry = 0;
        string ans = "";
        while (n1 >= 0 || n2 >= 0 || carry != 0)
        {
            int x = n1 >= 0 ? num1[n1] - '0' : 0;
            int y = n2 >= 0 ? num2[n2] - '0' : 0;
            int result = x + y + carry;
            ans.push_back(result % 10);
            carry = result / 10;
            n1--;
            n2--;
        }
        reverse(ans.begin(), ans.end());
        for (auto& c : ans)
            c += '0';
        return ans;
    }
};