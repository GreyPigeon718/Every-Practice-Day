#include <iostream>

class Solution {
public:
    int fun(int x, int y)
    {
        if (y == 0)
            return 1;
        if (y < 0)
            return 0;
        int m = 1, n = 1, z = x - y;
        while (x > z)
        {
            m *= x;
            x--;
        }
        while (y > 0)
        {
            n *= y;
            y--;
        }
        return m / n;
    }
    int paintingPlan(int n, int k) {
        if (k == 0)
            return 1;
        if (k < n)
            return 0;
        if (k == n * n)
            return 1;
        float i, j;
        int res = 0;
        for ( i = 0; i < n; i++)
        {
            float x = (k - i * n) / (n - i);
            if (x != (int)x)
                continue;
            j = (int)x;
            res += fun(n, i) * fun(n, j);
        }
    }
};