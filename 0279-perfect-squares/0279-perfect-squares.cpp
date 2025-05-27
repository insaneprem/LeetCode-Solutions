class Solution {
public:
    int numSquares(int n) {
        vector<int> prefect;
        for (int i = 1; i * i <= n; i++)
            prefect.push_back(i * i);

        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto num : prefect) {
                if (i - num >= 0)
                    dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }

        return dp[n];
    }
};