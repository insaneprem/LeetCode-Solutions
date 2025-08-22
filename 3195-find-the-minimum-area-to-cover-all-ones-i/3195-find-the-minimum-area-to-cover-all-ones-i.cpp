class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;

        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }

        if (left == INT_MAX)
            return 0;

        return (right - left + 1) * (bottom - top + 1);
    }
};