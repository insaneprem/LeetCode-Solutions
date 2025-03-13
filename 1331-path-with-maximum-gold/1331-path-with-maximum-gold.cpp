class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0)
            return 0;

        int ans = 0;
        int original = grid[i][j];
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            ans =
                max(ans, dfs(grid, i + dir[k].first, j + dir[k].second, n, m));
        }

        grid[i][j] = original;
        return ans + original;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(grid, i, j, n, m));
            }
        }

        return ans;
    }
};