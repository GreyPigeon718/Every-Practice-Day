// 有效的完全平方数
class Solution {
public:
    bool isPerfectSquare(int num) {
        if ((int)sqrt(num) * (int)sqrt(num) == num)
            return true;
        return false;
    }
};
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            long square = (long)mid * mid;
            if (square < num) {
                left = mid + 1;
            }
            else if (square > num) {
                right = mid - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};