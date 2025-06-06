class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int idx = i + questions[i][1] + 1;
            int points = questions[i][0];
            dp[i] = max(dp[i + 1], points + ((idx < n) ? dp[idx] : 0));
        }

        return dp[0];
    }
};