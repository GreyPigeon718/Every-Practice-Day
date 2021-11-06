// Ω””ÍÀÆ
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i)
            leftMax[i] = max(leftMax[i - 1], height[i]);

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; --j)
            rightMax[j] = max(rightMax[j + 1], height[j]);

        for (int i = 0; i < n; ++i)
            res += min(rightMax[i], leftMax[i]) - height[i];
        return res;
    }
};