class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<map<int, int>> dp(n);

        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = max(1 + dp[j][diff], dp[i][diff]);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans+1;
    }
};