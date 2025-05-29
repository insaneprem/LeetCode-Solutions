class Solution {
public:
    int dp[71][71][71];
    int n, m;
    int solve(int row, int col1, int col2, vector<vector<int>>& grid) {
        if (row == n)
            return 0;

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cherry = (col1 == col2) ? grid[row][col1]
                                    : grid[row][col1] + grid[row][col2];

        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nrow = row + 1;
                int nc1 = col1 + i;
                int nc2 = col2 + j;

                if (nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m) {
                    ans = max(ans, solve(nrow, nc1, nc2, grid));
                }
            }
        }

        return dp[row][col1][col2] = cherry + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m - 1, grid);
    }
};