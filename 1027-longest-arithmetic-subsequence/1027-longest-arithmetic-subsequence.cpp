class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<map<int, int>> dp(n);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans, dp[i][diff] + 1);
            }
        }

        return ans;
    }
};