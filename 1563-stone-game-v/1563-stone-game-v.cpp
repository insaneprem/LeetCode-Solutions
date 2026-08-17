class Solution {
private:
    vector<vector<int>> dp;

public:
    int dfs(const vector<int>& stoneValue, int left, int right) {
        if (left == right) {
            return 0;
        }
        if (dp[left][right]) {
            return dp[left][right];
        }

        int sum = accumulate(stoneValue.begin() + left, stoneValue.begin() + right + 1, 0);
        int suml = 0;
        for (int i = left; i < right; ++i) {
            suml += stoneValue[i];
            int sumr = sum - suml;
            if (suml < sumr) {
                dp[left][right] =
                    max(dp[left][right], dfs(stoneValue, left, i) + suml);
            } else if (suml > sumr) {
                dp[left][right] =
                    max(dp[left][right], dfs(stoneValue, i + 1, right) + sumr);
            } else {
                dp[left][right] =
                    max(dp[left][right], max(dfs(stoneValue, left, i),
                                            dfs(stoneValue, i + 1, right)) +
                                            suml);
            }
        }
        return dp[left][right];
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, vector<int>(n));
        return dfs(stoneValue, 0, n - 1);
    }
};