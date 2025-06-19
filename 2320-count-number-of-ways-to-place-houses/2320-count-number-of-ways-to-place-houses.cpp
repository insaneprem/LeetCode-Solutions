class Solution {
public:
    const int MOD = 1e9+7;
    int countHousePlacements(int n) {
        vector<long long> dp(n + 1);
        dp[0] = 1, dp[1] = 2;

        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;

        return (dp[n] * dp[n]) % MOD;
    }
};