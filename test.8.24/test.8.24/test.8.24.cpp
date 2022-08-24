class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int ans = 0;
        vector<int> line(matrix[0].size() + 2, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                line[j + 1] = (matrix[i][j] == '0') ? 0 : line[j + 1] + 1;
            }
            ans = max(ans, largestRectangleArea(line));
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        // heights.insert(heights.begin(), 0);
        // heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};
