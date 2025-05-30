class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        vector<unordered_map<long long, int>> dp(n); // dp[i][diff] = count of subsequences ending at i with that diff

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long) nums[i] - nums[j];
                int count = dp[j][diff];     // Count of sequences ending at j with this diff
                dp[i][diff] += count + 1;    // Extend those, and include the new pair (nums[j], nums[i])
                total += count;              // Only sequences with length >= 3 (hence use count, not count+1
            }
        }

        return (int)total;
    }
};
