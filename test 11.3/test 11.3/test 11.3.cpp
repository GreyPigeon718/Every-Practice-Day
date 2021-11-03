#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            int Min = INT_MAX;
            for (int j = 1; j * j <= i; ++j)
                Min = min(Min, v[i - j * j]);
            v[i] = Min + 1;
        }
        return v[n];
    }
};
//class Solution {
//public:
//    // �ж��Ƿ�Ϊ��ȫƽ����
//    bool isPerfectSquare(int x) {
//        int y = sqrt(x);
//        return y * y == x;
//    }
//
//    // �ж��Ƿ��ܱ�ʾΪ 4^k*(8m+7)
//    bool checkAnswer4(int x) {
//        while (x % 4 == 0) {
//            x /= 4;
//        }
//        return x % 8 == 7;
//    }
//
//    int numSquares(int n) {
//        if (isPerfectSquare(n)) {
//            return 1;
//        }
//        if (checkAnswer4(n)) {
//            return 4;
//        }
//        for (int i = 1; i * i <= n; i++) {
//            int j = n - i * i;
//            if (isPerfectSquare(j)) {
//                return 2;
//            }
//        }
//        return 3;
//    }
//};

int main()
{
    int x;
    cin >> x;
    Solution y;
    y.numSquares(x);
}