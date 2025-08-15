class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        int n = grid.size(), m = grid[0].size();

        for (int i = x, j = min(n - 1, x + k - 1); i < j; i++, j--) {
            for (int t = y; t < y + k; t++) {
                swap(grid[i][t], grid[j][t]);
            }
        }

        return grid;
    }
};