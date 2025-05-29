class Solution {
public:
    const int MOD = 1e9 + 7;
    int numMusicPlaylists(int n, int goal, int k) {
        long long dp[101][101] =
            {}; // number of playlist with i length and j unique songs

        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = ((n - j + 1) * dp[i - 1][j - 1]) % MOD;

                if (j - k >= 0)
                    dp[i][j] = (dp[i][j] + (j - k) * dp[i - 1][j]) % MOD;
            }
        }

        return dp[goal][n];
    }
};
