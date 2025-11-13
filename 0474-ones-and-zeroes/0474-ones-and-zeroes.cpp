class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // till index i if i have x zeros and y ones what maxium subset size can
        // i acheive

        int sz = strs.size();
        vector<vector<vector<int>>> dp(
            sz, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        vector<pair<int, int>> cnt(sz);

        for (int i = 0; i < sz; i++) {
            int one = count(begin(strs[i]), end(strs[i]), '1');
            int zero = strs[i].size() - one;

            cnt[i] = {zero, one};
        }

        int ans = 0;
        if (cnt[0].first <= m && cnt[0].second <= n) {
            dp[0][cnt[0].first][cnt[0].second] = 1;
            ans = 1;
        }

        for (int i = 1; i < sz; i++) {
            int currzero = cnt[i].first;
            int currone = cnt[i].second;

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
                    if (j >= currzero && k >= currone) {
                        dp[i][j][k] =
                            max(dp[i][j][k],
                                1 + dp[i - 1][j - currzero][k - currone]);
                    }

                    ans = max(ans, dp[i][j][k]);
                }
            }
        }

        return ans;
    }
};