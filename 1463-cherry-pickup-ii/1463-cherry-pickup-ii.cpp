class Solution {
public:
    int dp[77][77][77];
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        memset(dp, 0, sizeof(-1));

        for (int row = n - 1; row >= 0; row--) {
            for (int c1 = 0; c1 < m; c1++) {
                for (int c2 = 0; c2 < m; c2++) {
                    dp[row][c1][c2] = (c1 == c2)
                                          ? grid[row][c1]
                                          : grid[row][c1] + grid[row][c2];

                    int ans = 0;
                    for (int i = -1; i <= 1; i++) {
                        for (int j = -1; j <= 1; j++) {
                            int nrow = row + 1;
                            int nc1 = c1 + i;
                            int nc2 = c2 + j;

                            if (nc1 >= 0 && nc2 >= 0 && nc1 < m && nc2 < m)
                                ans = max(ans, dp[nrow][nc1][nc2]);
                        }
                    }

                    dp[row][c1][c2] += ans;
                }
            }
        }

        return dp[0][0][m - 1];
    }
};