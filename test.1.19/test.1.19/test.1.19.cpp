class Solution {
public:
    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int five = 0;
        int r = rand7();
        while (r == 7) {
            r = rand7();
        }
        five = r % 2;

        r = rand7();
        while (r >= 6) {
            r = rand7();
        }

        return r + five * 5;
    }
};
