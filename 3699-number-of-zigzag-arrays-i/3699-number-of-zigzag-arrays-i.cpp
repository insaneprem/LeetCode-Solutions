vector<vector<vector<int>>> dp(2000,
                               vector<vector<int>>(2000, vector<int>(2, 0)));
class Solution {
public:
    const int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        dp[0] = vector<vector<int>>(m, {1, 1});

        for (int i = 1; i < n; i++) {
            long long psum = 0;

            for (int j = 0; j < m; j++) {
                dp[i][j][0] = psum;
                psum += dp[i - 1][j][1];
                psum %= MOD;
            }

            long long sfsum = 0;
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j][1] = sfsum;
                sfsum += dp[i - 1][j][0];
                sfsum %= MOD;
            }
        }

        int ans = 0;

        for (int j = 0 ; j < m; j++) {
            ans =(ans + dp[n-1][j][1]) % MOD;
            ans =(ans + dp[n-1][j][0]) % MOD;
        }

        return ans;
    }
};
