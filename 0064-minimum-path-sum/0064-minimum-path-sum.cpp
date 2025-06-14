class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1)
                    dp[i][j] = grid[i][j];
                if (i < n - 1)
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + grid[i][j]);
                if (j < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + grid[i][j]);
            }
        }

        return dp[0][0];
    }
};