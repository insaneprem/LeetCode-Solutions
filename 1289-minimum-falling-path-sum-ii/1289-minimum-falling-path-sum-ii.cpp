class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    dp[i][j] = grid[i][j];
                else {
                    int val = 1e9;
                    for (int k = 0; k < n; k++)
                        if (k != j)
                            val = min(val, dp[i - 1][k]);
                    dp[i][j] = val + grid[i][j];
                }
            }
        }

        for (auto i : dp) {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }

        return *min_element(begin(dp[n - 1]), end(dp[n - 1]));
    }
};