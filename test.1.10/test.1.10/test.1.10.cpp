//ԲȦ�����ʣ�µ�����
class Solution {
public:
    int fun(int n, int m)
    {
        if (n == 1)
            return 0;
        int x = fun(n - 1, m);
        return (m + x) % n;
    }
    int lastRemaining(int n, int m) {
        return fun(n, m);
    }
};