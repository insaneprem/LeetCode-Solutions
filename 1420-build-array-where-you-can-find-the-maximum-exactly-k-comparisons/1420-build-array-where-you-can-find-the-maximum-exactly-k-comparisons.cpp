class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));

        for (int j = 1; j <= m; j++)
            dp[1][j][1] = 1;

        for (int len = 2; len <= n; len++) {
            for (int maxVal = 1; maxVal <= m; maxVal++) {
                for (int cost = 1; cost <= k; cost++) {
                    int v = dp[len-1][maxVal][cost];
                    for (int l = 1; l <= maxVal; l++)
                        dp[len][maxVal][cost] =
                            (dp[len][maxVal][cost] + v) % MOD;
                    // dp[len][maxVal][cost] = (dp[len - 1][maxVal][cost] *
                    // maxVal) % MOD;

                    for (int prevMax = 1; prevMax < maxVal; prevMax++) {
                        dp[len][maxVal][cost] =
                            (dp[len][maxVal][cost] +
                             dp[len - 1][prevMax][cost - 1]) %
                            MOD;
                    }
                }
            }
        }

        int res = 0;

        for (int j = 1; j <= m; j++)
            res = (res + dp[n][j][k]) % MOD;

        return res;
    }
};