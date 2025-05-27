class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(maxMove + 1, 0)));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto dir : dirs) {
                        int ni = i + dir.first;
                        int nj = j + dir.second;

                        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                            dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
                        else {
                            dp[i][j][k] += dp[ni][nj][k - 1];
                            dp[i][j][k] %= MOD;
                        }
                    }
                }
            }
        }

        return dp[startRow][startColumn][maxMove];
    }
};