//> 1��n ������ 1 ���ֵĴ���
class Solution {
public:
    int countDigitOne(int n) {
        // mulk ��ʾ 10^k
        // ������Ĵ����У����Է��� k ��û�б�ֱ��ʹ�õ�������ʹ�� 10^k��
        // ��Ϊ���ô��뿴��������ֱ�ۣ����ﱣ���� k
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }
};
