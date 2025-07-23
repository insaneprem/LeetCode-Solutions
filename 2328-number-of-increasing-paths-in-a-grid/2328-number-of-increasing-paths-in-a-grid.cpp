class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    const int MOD = 1e9 + 7;
    bool isValid(int x, int y) { return (x < n && y < m && x >= 0 && y >= 0); }
    int dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[x][y] != -1)
            return dp[x][y];

        int ans = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];

            if (isValid(nx, ny) && grid[nx][ny] > grid[x][y]) {
                ans = (ans + dfs(nx, ny, grid, dp)) % MOD;
            }
        }

        return dp[x][y] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        this->n = grid.size(), this->m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = (ans + dfs(i, j, grid, dp)) % MOD;
            }
        }

        return ans;
    }
};