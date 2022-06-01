//> ��ʾ��ֵ���ַ���
class Solution {
private:
    // �����ĸ�ʽ������[+|-]B��ʾ, ����BΪ�޷�������
    bool scanInteger(const string s, int& index) {
        if (s[index] == '+' || s[index] == '-')
            ++index;
        return scanUnsignedInteger(s, index);
    }
    bool scanUnsignedInteger(const string s, int& index) {
        int befor = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > befor;
    }
public:
    // ���ֵĸ�ʽ������A[.[B]][e|EC]����.B[e|EC]��ʾ��
    // ����A��C���������������������ţ�Ҳ����û�У�����B��һ���޷�������
    bool isNumber(string s) {
        if (s.size() == 0)
            return false;
        int index = 0;
        //�ַ�����ʼ�пո񣬿��Է���true
        while (s[index] == ' ')  //���д���û�и������
            ++index;
        bool numeric = scanInteger(s, index);
        // �������'.'�������������ֵ�С������
        if (s[index] == '.') {
            ++index;
            // ����һ�д�����||��ԭ��
            // 1. С������û���������֣�����.123����0.123��
            // 2. С����������û�����֣�����233.����233.0��
            // 3. ��ȻС����ǰ��ͺ�����������֣�����233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }
        // �������'e'����'E'�����������ŵ������ֵ�ָ������
        if (s[index] == 'e' || s[index] == 'E') {
            ++index;
            // ����һ�д�����&&��ԭ��
            // 1. ��e��Eǰ��û������ʱ�������ַ������ܱ�ʾ���֣�����.e1��e1��
            // 2. ��e��E����û������ʱ�������ַ������ܱ�ʾ���֣�����12e��12e+5.4
            numeric = numeric && scanInteger(s, index);
        }
        //�ַ�����β�пո񣬿��Է���true
        while (s[index] == ' ')
            ++index;
        return numeric && index == s.size();//����Ƿ����в��ֶ����ϣ���1a3ֻ�����һ����������Ȼ����a�Ͳ����������ˣ�index!=size�����Է���false
    }
};

//> ���ƴ������
class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
        if (index == matchsticks.size()) {
            return true;
        }
        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int totalLen = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (totalLen % 4 != 0) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // ����������

        vector<int> edges(4);
        return dfs(0, matchsticks, edges, totalLen / 4);
    }
};
