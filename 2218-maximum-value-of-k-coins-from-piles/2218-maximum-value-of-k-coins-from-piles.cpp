class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[1001][2001];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= piles.size(); i++) {
            for (int j = 0; j <= k; j++) {
                int ntake = dp[i - 1][j];

                int take = 0, sum = 0;
                for (int a = 0; a < min(j, (int) piles[i - 1].size()); a++) {
                    sum += piles[i - 1][a];
                    take = max(take, sum + dp[i - 1][max(0, j - (a + 1))]);
                }
                dp[i][j] = max(take, ntake);
            }
        }

        return dp[piles.size()][k];
    }
};