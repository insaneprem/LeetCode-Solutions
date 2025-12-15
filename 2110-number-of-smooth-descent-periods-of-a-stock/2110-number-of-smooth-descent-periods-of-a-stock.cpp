class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n, 1);
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1)
                dp[i] += dp[i - 1];

            ans += dp[i];
        }

        return ans;
    }
};