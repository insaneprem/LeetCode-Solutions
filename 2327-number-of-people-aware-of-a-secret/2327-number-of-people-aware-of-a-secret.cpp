class Solution {
public:
    const int MOD = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(n + 1, vector<int>(forget + 1, 0));


        dp[1][forget] = 1;
        for (int day = 2; day <= n; day++) {
            long long ans = 0;
            for (int j = 1; j <= forget; j++) {
                if (j < forget)
                    dp[day][j] = dp[day - 1][j + 1];
                if (day - delay >= 0 && j > delay)
                    ans = (ans + dp[day - delay][j]) % MOD;
            }
            dp[day][forget] = ans;
        }

        // for (auto i : dp) {
        //     for (auto j : i)
        //         cout << j << " ";
        //     cout << endl;
        // }

        int ans = 0;
        for (auto &i : dp[n])
            ans = (ans + i) % MOD;

        return ans;
    }
};