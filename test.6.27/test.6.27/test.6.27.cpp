//> �� N λ����
class Solution {
public:
    int findNthDigit(int n) {
        long long N = n;
        int digits = 1; // λ��
        long long border = 9; // digitsλ��һ����������λ����

        //> ���ҵ��ĸ�����
        while (N) {
            if (N <= border * digits) break; // ѭ���˳�ʱ���ҵ��˵�ǰ���ֵ�λ��
            N -= border * digits; // N Ϊ�۵�����digitsλ���֣�����2λ��������������֮��ʣ���ٸ�����
            digits++;
            border *= 10;
        }
        // ѭ�������� ʣ���N������ digitsλ�� ���׵�
        // ÿ�� digitsλ�� �������� digits�����֣� ��������������Ϳ���֪��n��Ӧ���ǵڼ���digitsλ��
        int offset = (N - 1) / digits;
        int begin = 1; // ���ڼ�����С�� digitsλ��
        for (int i = 0; i < digits - 1; i++) {
            begin *= 10;
        }
        int mod = (N - 1) % digits;
        string target = to_string(offset + begin);
        int ans = target[mod] - '0';

        return ans;
    }
};