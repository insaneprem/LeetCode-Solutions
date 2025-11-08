class Solution {
public:
    int minArraySum(vector<int>& nums, int maxK, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= op1; j++) {
                for (int k = 0; k <= op2; k++) {
                    int ntake = dp[i + 1][j][k] + nums[i];
                    int d = INT_MAX, sub = INT_MAX;

                    if (j + 1 <= op1) {

                        d = (nums[i] + 1) / 2;
                        d += dp[i + 1][j + 1][k];
                    }

                    if (k + 1 <= op2 && nums[i] - maxK >= 0) {
                        sub = nums[i] - maxK;
                        sub += dp[i + 1][j][k + 1];
                    }

                    int both = INT_MAX;

                    int val = nums[i];

                    if (j + 1 <= op1) {
                        val = (val + 1) / 2;
                        if (k + 1 <= op2 && val - maxK >= 0) {
                            val = val - maxK;
                            both = min(both, val + dp[i + 1][j + 1][k + 1]);
                        }
                    }

                    val = nums[i];

                    if (k + 1 <= op2 && val - maxK >= 0) {
                        val = val - maxK;
                        if (j + 1 <= op1) {
                            val = (val + 1) / 2;
                            both = min(both, val + dp[i + 1][j + 1][k + 1]);
                        }
                    }

                    dp[i][j][k] = min({ntake, d, sub, both});
                }
            }
        }

        return dp[0][0][0];
    }
};