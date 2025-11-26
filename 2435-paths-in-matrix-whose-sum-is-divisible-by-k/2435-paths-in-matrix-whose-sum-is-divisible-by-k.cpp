class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        dp[n - 1][m - 1][grid[n - 1][m - 1] % k] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1)
                    continue;

                int currmod = grid[i][j] % k;
                for (int l = 0; l <= k; l++) {
                    if (i + 1 < n) {
                        dp[i][j][(l + currmod) % k] =
                            (dp[i][j][(l + currmod) % k] + dp[i + 1][j][l]) %
                            MOD;
                    }
                    if (j + 1 < m) {
                        dp[i][j][(l + currmod) % k] =
                            (dp[i][j][(l + currmod) % k] + dp[i][j + 1][l]) %
                            MOD;
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};