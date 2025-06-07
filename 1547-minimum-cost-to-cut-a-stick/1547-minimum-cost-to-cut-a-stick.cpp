class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int l = 0; l + len < m; l++) {
                int r = l + len;
                dp[l][r] = INT_MAX;
                for (int i = l + 1; i < r; i++) {
                    dp[l][r] =
                        min(dp[l][r], dp[l][i] + dp[i][r] + cuts[r] - cuts[l]);
                }
            }
        }

        return dp[0][m - 1]; 
    }
};
