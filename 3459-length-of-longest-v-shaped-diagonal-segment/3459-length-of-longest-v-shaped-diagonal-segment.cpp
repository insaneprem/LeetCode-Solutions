class Solution {
public:
    vector<vector<int>> dirs = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int dfs(int i, int j, int k, int canTurn, int target,
            vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        i += dirs[k][0];
        j += dirs[k][1];
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] != target) {
            return 0;
        }
        int mask = (k << 1) | canTurn;
        if (dp[i][j][mask] > 0)
            return dp[i][j][mask];

        int res = dfs(i, j, k, canTurn, 2 - target, grid, dp);
        if (canTurn == 1) {
            vector<int> maxs = {(int)grid.size() - i - 1, j, i,(int)grid[0].size() - j - 1};
            int nk = (k + 1) % 4;
            if (maxs[nk] > res) {
                res = max(res, dfs(i, j, nk, 0, 2 - target, grid, dp));
            }
        }
        return dp[i][j][mask] = res + 1;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(1 << 3, 0)));
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1)
                    continue;
                vector<int> maxs = {m - i, j + 1, i + 1, n - j};
                for (int k = 0; k < 4; k++) {
                    if (maxs[k] > ans) {
                        ans = max(ans, dfs(i, j, k, 1, 2, grid, dp) + 1);
                    }
                }
            }
        }
        return ans;
    }
};